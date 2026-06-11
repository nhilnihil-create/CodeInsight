#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>
#include<stack>
#include <map>
#define ll                   long long
#define skip                 cin>>ws;
#define vll                  vector<ll> 
#define vb                   vector<bool>
#define vpll                 vector<pair<ll,ll>>
#define vvll                 vector<vector<ll>>
#define pll                  pair<ll,ll>
#define vs                   vector<string>
#define vvpll                vector<vector<pair<ll, ll>>>
#define pb                   push_back
#define pob                  pop_back()
#define MOD                  (ll)(1e9 + 7)
#define INF                  (ll)(1e18 + 5)
#define count1(n)            __builtin_popcountll(n)
#define                      test ll t; cin>>t; while(t--)

using namespace std;

void enter(vll &ar)
{
    ll n = ar.size();
    for(ll i=0;i<n;i++) cin>>ar[i];
}

void show(vll &a)
{
    ll n = a.size();
    for(ll i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

void SieveOfErat1sthenes(ll n, vll &pri) 
{ 
    vb prime(n+1, true); 
   
    for (ll p=2; p*p<=n; p++) 
    { 
        
        if (prime[p] == true) 
        { 
            pri.pb(p);
            
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}

ll mo(ll a)
{
    return a%MOD;
}

ll maxn, n;
vvll mat;
vvll dp;

ll solve(ll mask, ll l)
{
    if(mask==maxn) return 1;
    if(l>=n) return 0;

    if(dp[mask][l]!=-1) return dp[mask][l];
    ll res = 0; 

    for(ll i=0;i<n;i++)
    {
        if(mask&(1<<i)) continue;

        if(mat[l][i])
        {
            res = mo(mo(res) + mo(solve(mask|(1<<i), l+1)));
        }
    }

    return dp[mask][l] = mo(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    maxn = (1<<n) - 1;
    dp.assign(maxn, vll(n, -1));

    mat.resize(n, vll(n, 0));

    for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cin>>mat[i][j];

    ll ans = solve(0, 0);
    cout<<ans<<"\n";

    return 0;
}