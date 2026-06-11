 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 100005
int a[m],b[m],c[m],dp[3][m];
int main()
{
   ll n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i]>>b[i]>>c[i];
   }
   for(int i=1;i<=n;i++)
   {
       dp[0][i]=max(dp[1][i-1],dp[2][i-1])+a[i];
       dp[1][i]=max(dp[0][i-1],dp[2][i-1])+b[i];
       dp[2][i]=max(dp[0][i-1],dp[1][i-1])+c[i];
  }
  cout<<max({dp[0][n],dp[1][n],dp[2][n]})<<endl;
}
