#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100][2];

int main()
{
	cin >> n;
	int maxx = 0;
	int left = 0;
	int right = 0;
	for(int j = 0;j<n;j++) cin >> arr[j][0];
	for(int j = 0;j<n;j++)
	{
		cin >> arr[j][1];
		right += arr[j][1];
	}
	if(n>=2)
	{
		for(int j = 0;j<n;j++)
		{
			left += arr[j][0];
			if(j>=1) right -= arr[j-1][1];
			if(right + left > maxx) maxx = right + left;
		}
	}
	else maxx = arr[0][0] + arr[0][1];
	cout << maxx;
	
	return 0;
}