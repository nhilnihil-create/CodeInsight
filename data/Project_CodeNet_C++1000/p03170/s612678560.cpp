#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	bool dp[k+1];
	for(i=0;i<=k;i++)
	{
		dp[i] = false;
		for(int j = 0;j<n;j++)
		{
			if(a[j]>i)
				break;
			if(dp[i-a[j]]==false)
			{
				dp[i] = true;
				break;
			}
		}
	}
	if(dp[k]==false)
		cout<<"Second";
	else
		cout<<"First";
	return 0;

}
