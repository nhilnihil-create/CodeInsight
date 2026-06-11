#include <bits/stdc++.h>
# define lli long long int
# define pb push_back
# define ff first
#define ss second
using namespace std;
lli n;
lli dp[100005]={0},a[100005]={0};
lli find(lli n)
{
     for(lli i=2;i<n;i++)
     {
          lli op1=abs(a[i]-a[i-1])+dp[i-1];
          lli op2=abs(a[i]-a[i-2])+dp[i-2];
          dp[i]=min(op1,op2);
     }
     return dp[n-1];
}
int main()
{
     lli n,j;
     cin>>n;
     for(j=0;j<n;j++)
     {
          cin>>a[j];
     }
     dp[1]=abs(a[0]-a[1]);
     cout<<find(n);
}
