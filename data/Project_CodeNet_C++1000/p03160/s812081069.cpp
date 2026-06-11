#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int static dp[100001];
int frog(vector<int>&a,int n,int current)
{
    if(current+1==n)
        return 0;
    if(dp[current]!=-1)
        return dp[current];
    int A=INT_MAX,B=INT_MAX;
    if(current+1<n)
        A=abs(a[current]-a[current+1])+frog(a,n,current+1);
    if(current+2<n)
        B=abs(a[current]-a[current+2])+frog(a,n,current+2);
    dp[current]=min(A,B);
    return dp[current];
}

int main() {
    memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	vector<int>height;
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;
	    height.push_back(x);
	}
	cout<<frog(height,n,0);
	return 0;
}