// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double

#define pll pair<ll,ll>
#define ff first
#define ss second

#define pb push_back
#define all(x) x.begin(),x.end()

#define MOD  1000000007
const int N = 22; 

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

ll dp[(1<<N)],n,a[N][N];

ll solve1(ll mask)
{
    ll one = __builtin_popcountll(mask);
    if(one==n)    return 1;
    ll &ans = dp[mask];
    if(ans!=-1)   return ans;
    ans = 0;
    for(ll i=0;i<n;i++)
    {
        if(a[one][i] && !(mask & (1<<i)))    ans = (ans + solve1(mask^(1<<i)) ) % MOD;
    }
    return ans;
}

void solve()
{
    cin >> n;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)   cin >> a[i][j];
    } 
    memset(dp,-1,sizeof(dp));
    ll ans = solve1(0);
    cout<<ans;
}

int main()
{
    FAST;
    int t = 1;
 // cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}