#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;
 
int solution(int arr[], int & n)
{
	int sum = 1;
	sort(arr,arr+n);
	for(int i = 0; i < n-1; i++)
		if( arr[i] != arr[i+1] )
			sum++;
	return sum;
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solution(arr,n);
}