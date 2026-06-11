#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    ll test = 1;
    //cin >> test;
    while(test--)
    {
		ll n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		vector<int> dp (n, 0);
		dp[0] = 0;
		dp[1] = abs(arr[1]-arr[0]);
		for(int i=2; i<n; i++)
		{
			dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
		}
		cout<<dp[n-1]<<"\n";
	}
    return 0;
}
