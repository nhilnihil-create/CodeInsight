#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define w(x) int x; cin>>x; while(x--)
#define f(i,n) for(ll i=0;i<n;i++)
#define ff first
#define ss second
const ll INF = 1e18 + 5;

void ganekasar()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void add_self(ll& a, ll b)
{
    a += b;

    if(a >= mod)
        a -= mod;
}

int main() 
{
    ganekasar();
    
    ll n;
    cin>>n;

    vector<vector<ll>> can(n, vector<ll>(n));

    f(i, n) f(j ,n) cin>>can[i][j];

    vector<ll> dp(1<<n);
    
    dp[0] = 1;

    for(ll mask=0; mask < (1<<n)-1; mask++)
    {
        ll a = __builtin_popcount(mask);

        for(ll b=0; b<n; b++)
        {
            if(can[a][b] && !(mask & (1<<b)))
            {
                ll m2 = mask^(1<<b);
                add_self(dp[m2], dp[mask]);
            }
        }
    }

    cout<<dp[(1<<n)-1]<<endl;

    return 0; 
} 