#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

string check(int arr[], int n)
{
	for(int j = 0; j < n-1; j++)
		for(int i = 0; i < n-1; i++)
			if( arr[ i*n + j ] - arr[ i*n + j + 1 ] != arr[ (i+1)*n + j ] - arr[ (i+1)*n + j + 1])
				return "No";
	return "Yes";
}
int main()
{
	int arr[9];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> arr[i*3+j];
	cout << check(arr,3);
}