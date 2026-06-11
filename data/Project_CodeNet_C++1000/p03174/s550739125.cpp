#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int dp[22][1<<22];
int32_t main() {
    nitin;
    int n;
    cin>>n;
    int a[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i+1][j+1];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=1;
        for(int j=1 ;j<(1<<n);j++)
        {
            dp[i][j]=dp[i-1][j];
            if(setbits(j)!=i)
                continue;
            for(int k=1;k<=n;k++)
            {
                int p=j;
                int q=(1<<(k-1));
                if((j&(1<<(k-1)))>0 && a[i][k]==1)
                {
                    int mask=(j^(1<<(k-1)));
                    dp[i][j]=(dp[i][j]+dp[i-1][mask])%mod;
                }
            }
        }
    }
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<(1<<n);j++)
//            cout<<dp[i][j]<<","<<setbits(j)<<"  ";
//        cout<<endl;
//    }
cout<<dp[n][(1<<n)-1];;
    return 0;
}