#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[(1<<22)];
int n;
int a[25][25];
int fun(int mask)
{
    if(mask==(1<<n)-1)
        return 1;
    int &ret=dp[mask];
    if(~ret) return ret;
    ret=0;
    int men=__builtin_popcount(mask);
    for(int i=0;i<n;i++)
    {
      if(a[men][i]&&!((1<<i)&mask))
      {
          ret+=fun(mask|(1<<i));
          ret%=mod;
      }
    }
    return ret;
}
signed main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    cout<<fun(0)<<endl;
	return 0;
}
