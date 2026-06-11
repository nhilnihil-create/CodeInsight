#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int solve(vector<int>&v,int n,int start)
{
if(start==n)
return 0;
if(start==n-1)
return abs(v[start-1]-v[n-1]);
if(dp[start]!=-1)
return dp[start];
int a=abs(v[start-1]-v[start+1]);
int b=abs(v[start-1]-v[start]);
if(dp[start+2]==-1)
a+=solve(v,n,start+2);
else
a+=dp[start+2];
if(dp[start+1]==-1)
b+=solve(v,n,start+1);
else
b+=dp[start+1];
int j= min(a,b);
dp[start]=j;
return j;
}
int main(){
   int n;
   cin>>n;
   vector<int>v(n);
   for (int i = 0; i < n; i++) {
      cin>>v[i];
   }
   memset(dp,-1,sizeof(dp));
   int r=solve(v,n,1);
   cout<<r<<endl;
   return 0;
}