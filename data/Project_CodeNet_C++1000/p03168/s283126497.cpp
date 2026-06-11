#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))

long double a[3000];
long double dp[1500][3000];

long double probOfHeads(int countOfT,int n)
{
  if(n==0)
  return 1.0;
  if(dp[countOfT][n]!=-1.0)
  return dp[countOfT][n];
  long double ans=0.0;
  ans+= probOfHeads(countOfT,n-1)*a[n-1];
  if(countOfT>0)
  ans+= probOfHeads(countOfT-1,n-1)*(1.0-a[n-1]);
  return dp[countOfT][n]=ans;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    int countOfT;
    if(n%2==0)
    countOfT=n/2-1;
    else
    countOfT=n/2;
    for(i=0;i<=countOfT;i++)
      for(j=0;j<=n;j++)
        dp[i][j]=-1.0;

    cout<<fixed<<std::setprecision(10);
    cout<<probOfHeads(countOfT,n);
    return 0;
}