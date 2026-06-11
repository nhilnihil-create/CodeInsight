#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
	int n;
	cin >> n;
	int arr[n], alice = 0, bob = 0;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr,arr+n);
	for(int i = n-1; i >= 0; i -= 2)
		alice += arr[i];
	for(int i = n-2; i >= 0; i -= 2)
		bob += arr[i];
	cout << alice - bob;
}