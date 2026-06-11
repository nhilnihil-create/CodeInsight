#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[500][500];
long long int min(long long int a,long long int b)
{
    if(a>b) return b;
    return a;
}
long long int util(vector<long long int>&v,int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    long long int tot=0;
    for(int in = i;in<=j;in++)
    {
        tot+=v[in];
    }
    long long int mi = LLONG_MAX;
    for(int k=i;k<j;k++)
    {
        long long int temp = tot+util(v,i,k)+util(v,k+1,j);
        mi = min(mi,temp);
    }
    dp[i][j]=mi;
    return mi;
}
int main() {
	int n;
	cin>>n;
	vector<long long int>v(n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
	    cin>>v[i];
	}
	cout<<util(v,0,n-1)<<endl;
	return 0;
}