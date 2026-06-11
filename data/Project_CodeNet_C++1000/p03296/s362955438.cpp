#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 0;
	int arr[10000];
	cin >> n;
	int res = 0;
	for (int i = 0; i < n ; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n-1; i++)
	{
		if( arr[i] == arr[i+1])
		{
			arr[i+1] = 0;
			res++;
		}
	}
	cout << res;
	
}