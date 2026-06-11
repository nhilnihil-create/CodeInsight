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
int dp[101][100001];
int32_t main() {
    nitin;
    int n,k;
    cin>>n>>k;
    vector<int>v(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=n;i>=1;i--)
    {
        dp[i][0]=1;
        for(int j=1;j<=k;j++)
        {
            if(i!=n)
            {
                if(j>=v[i]+1)
                dp[i][j]=((dp[i][j]+dp[i][j-1])%mod+(dp[i+1][j]-dp[i+1][j-v[i]-1]+mod)%mod)%mod;
                else
                    dp[i][j]=((dp[i][j]+dp[i][j-1])%mod+dp[i+1][j])%mod;
            } else
            {
                if(j<=v[n])
                    dp[n][j]=1;
            }
        }
    }
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=k;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<dp[1][k]<<endl;
    return 0;
}