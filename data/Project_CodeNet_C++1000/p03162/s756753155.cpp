#include<bits/stdc++.h>
using namespace std;
int bu(int n,int a[],int b[],int c[])
{
   int dp[n+1][3];
   dp[1][0]=a[0];
   dp[1][1]=b[0];
   dp[1][2]=c[0];
   for(int i=2;i<=n;i++)
   {
       dp[i][0]=a[i-1]+max(dp[i-1][1],dp[i-1][2]);
       dp[i][1]=b[i-1]+max(dp[i-1][0],dp[i-1][2]);
       dp[i][2]=c[i-1]+max(dp[i-1][1],dp[i-1][0]);
   }
   return max(max(dp[n][0],dp[n][1]),dp[n][2]);

}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<bu(n,a,b,c);
}
