#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define pa pair<int,int>
const int N=1e5+10;
const int mod=1e9+7;
using namespace std;

int a[5005];
ll dp[5005];
int main()
{   
    ll n,A,B; scanf("%lld%lld%lld",&n,&A,&B);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    a[n+1]=n+1;
  for(int i=1;i<=n+1;++i)
  {
     dp[i]=1e18;
     int big=0;
     for(int j=i-1;j>=0;j--) 
     {
       if(a[i]<a[j]) big++;
       else dp[i]=min(dp[i],dp[j]+A*big+B*(i-1-j-big));
     }
  }
  printf("%lld\n",dp[n+1]);
return 0;
}
/*
*/