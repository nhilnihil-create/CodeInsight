#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	int arr[n];
	vector<pair<int,int>>move;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	//int c=0;
	int max=-1000006,min=1000006,maxind=0,minind=0;
	for(int i=0;i<n;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
			maxind=i;
		}
		if(min>arr[i])
		{
			min=arr[i];
			minind=i;
		}
	}
	cout<<2*n-1<<"\n";
	if(abs(max)<abs(min))
	{
		for(int i=0;i<n;i++)
			cout<<minind+1<<" "<<i+1<<"\n";
		for(int i=n-1;i>0;i--)
			cout<<i+1<<" "<<i<<"\n";
	}
	else
	{
		for(int i=0;i<n;i++)
			cout<<maxind+1<<" "<<i+1<<"\n";
		for(int i=0;i<n-1;i++)
			cout<<i+1<<" "<<i+2<<"\n";
	}
}