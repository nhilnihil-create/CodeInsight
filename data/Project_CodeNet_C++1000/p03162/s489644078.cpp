#include<bits/stdc++.h>

using namespace std;

#define ll long long

int dp[100005][3];

int solve(int day,int n,vector<int> arr[],int flag)
{
	int maxi=0;
	if(day==n)
		return 0;
	if(dp[day][flag]!=-1)
		return dp[day][flag];
	if(flag==0)
	{
		maxi=max(maxi,arr[day][0]+solve(day+1,n,arr,1));
		maxi=max(maxi,arr[day][1]+solve(day+1,n,arr,2));
		maxi=max(maxi,arr[day][2]+solve(day+1,n,arr,3));
	}
	else if(flag==1)
	{
		maxi=max(maxi,arr[day][1]+solve(day+1,n,arr,2));
		maxi=max(maxi,arr[day][2]+solve(day+1,n,arr,3));
	}
	else if(flag==2)
	{
		maxi=max(maxi,arr[day][0]+solve(day+1,n,arr,1));
		maxi=max(maxi,arr[day][2]+solve(day+1,n,arr,3));
	}
	else
	{
		maxi=max(maxi,arr[day][0]+solve(day+1,n,arr,1));
		maxi=max(maxi,arr[day][1]+solve(day+1,n,arr,2));
	}
	dp[day][flag]=maxi;
	return maxi;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	int n;
	cin>>n;
	vector<int> arr[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			int temp;
			cin>>temp;
			arr[i].push_back(temp);
		}
	}
	for(int i=0;i<100005;i++)
	{
		for(int j=0;j<3;j++)
			dp[i][j]=-1;
	}
	cout<<solve(0,n,arr,0);
}