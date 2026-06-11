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
int dp[401][401];
int32_t main() {
    nitin;
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[0]=0;
    for(int i=1;i<=n;i++)
        a[i]=a[i]+a[i-1];
    for(int j=2;j<=n;j++)
    {
        int si=1;
        int sj=j;
        while(si<=n && sj<=n)
        {
            dp[si][sj]=inf;

            for(int p=si;p<sj;p++)
                dp[si][sj]=min(dp[si][p]+dp[p+1][sj]+a[sj]-a[si-1],dp[si][sj]);

            si++;
            sj++;
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}