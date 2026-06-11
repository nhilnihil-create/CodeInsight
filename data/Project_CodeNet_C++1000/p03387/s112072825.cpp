#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int arr[3], sum = 0;
	cin >> arr[0] >> arr[1] >> arr[2];
	
	sort(arr,arr+3);
	sum += arr[2] - (arr[1]+arr[0]+1)/2;
	
	if( arr[0]%2 != arr[1]%2 )
		sum += 2;

	cout << sum;
}