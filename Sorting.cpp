#include <iostream>
using namespace std;


/*
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program: To introduce two sorting methods: merge sort and bubble sort.
Last updated: 11/19/2019 @ 11:00pm
*/

void bubbleSort(int arr[], int size);
void mergeSort(int* arr, int low, int high);
void merge(int* arr, int low, int high, int middle);


int main()
{
	int arr[] = { 1,2,4,5,3,0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int arr2[] = { 10,8,9,11,12,15 };
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	bubbleSort(arr,size);
	cout << "Elements were sorted with bubble sort" << endl;
	cout << "[" << " ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << " ]" << endl;



	mergeSort(arr2, 0, size2 - 1);

	cout << "Sorted with merge sort" << endl;
	cout << "[ " << "";
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " "; 
	}
	cout << " ]";


	
	return 0; 
}

/*
	@param arr - an array of integers 
	@param size - the amount of elements in the array 
*/
void bubbleSort(int arr[], int size)
{	
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < (size - i - 1); ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


}

/*
	@param arr- pointer to the array of integers
	@param low -  the first index of the array 
	@param high - the last index of the array 
*/
void mergeSort(int* arr, int low, int high)
{

	if (low < high) {
		int mid = (low + high) / 2;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, high, mid);
	}

}

/*
	@param arr - pointer to the int array 
	@param low- the first index of the array 
	@param high - the last index of the array 
	@param middle - the middle index of the array 
*/
void merge(int* arr, int low, int high, int middle)
{
	int i, j, k;
	int newArr[50];
	i = low;
	k = low;
	j = middle + 1;

	while (i <= middle && j <= high)
	{
		if (arr[i] < arr[j])
		{
			newArr[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			newArr[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= middle)
	{
		newArr[k] = arr[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		newArr[k] = arr[j];
		k++;
		j++;
	}

	//transferring the elements from the array made into the original one 
	for (i = low; i < k; i++)
	{
		arr[i] = newArr[i];
	}



}

