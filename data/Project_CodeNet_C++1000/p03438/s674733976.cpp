#include<bits/stdc++.h>
using namespace std;
long long arr[1000000],arr1[1000000];
int main()
{
	long long n,i,j,ans,k;
	ans=0;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for (i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	for (i=0;i<n;i++)
	{
		if (arr[i]<arr1[i])
		{
			ans+=(arr1[i]-arr[i])/2;
		}
		else
		{
			ans-=(arr[i]-arr1[i]);
		}
		//cout<<ans<<endl;
	}
	if (ans>=0)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}