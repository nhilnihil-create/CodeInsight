#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
int dp[20][150][2];
int getsum(int n,int sum,int flag,int ind)
{
	if(ind>n)return sum;
	int limit=9;
	if(!flag)limit = arr[ind];
	if(dp[ind][sum][flag]!=-1)return dp[ind][sum][flag];
	int res=0;
	for(int i=0;i<=limit;i++)
	{
		if(flag || i<limit)
		{
			res = max(res,getsum(n,sum+i,true,ind+1));
		}
		else {
			res = max(res,getsum(n,sum+i,false,ind+1));
		}
	}
	return dp[ind][sum][flag]=res;
}
int main() {
	// your code goes here
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned long long n;
	while(cin>>n)
	{
		int k=0;
		memset(dp,-1,sizeof(dp));
		arr.clear();
		// arr.push_back;
		while(n>0)
		{
			arr.push_back(n%10);
			n/=10;
			k++;
		}
		reverse(arr.begin(),arr.end());
		arr.resize(k);
		int res = getsum(k-1,0,0,0);
		cout<<res<<endl;
	}
	return 0;
}