#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int static dp[100001][4];
int vacation(vector<int>&a,vector<int>&b,vector<int>&c,int n,int current,int s=0)
{
    if(current==n)
        return 0;
     if(dp[current][s]!=-1)
         return dp[current][s];
    int A=INT_MIN,B=INT_MIN,C=INT_MIN;
    if(s==0||s==1)
        A=max(b[current]+vacation(a,b,c,n,current+1,2),c[current]+vacation(a,b,c,n,current+1,3));
    if(s==0||s==2)
        B=max(a[current]+vacation(a,b,c,n,current+1,1),c[current]+vacation(a,b,c,n,current+1,3));
    if(s==0||s==3)
        C=max(a[current]+vacation(a,b,c,n,current+1,1),b[current]+vacation(a,b,c,n,current+1,2));
    dp[current][s]=max(max(A,B),C);
    return dp[current][s];
    
}

int main() {
    memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	vector<int>a,b,c;
	for(int i=0;i<n;i++)
	{
	    int aa,bb,cc;
	    cin>>aa>>bb>>cc;
	    a.push_back(aa);
	    b.push_back(bb);
	    c.push_back(cc);
	}
	cout<<vacation(a,b,c,n,0);
	return 0;
}