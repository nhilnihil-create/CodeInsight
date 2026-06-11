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
#define ll long long int
#define skip cin>>ws;
#define vll vector<ll> 
#define vb vector<bool>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define vs vector<string>
#define vvpll vector<vector<pair<ll, ll>>>
#define pb push_back
#define pob pop_back()
#define MOD (ll)(1e9 + 7)
#define test ll t; cin>>t; while(t--)

using namespace std;

void enter(vll &ar)
{
    ll n = ar.size();

    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
    }
}

void show(vll &a)
{
    ll n = a.size();

    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void SieveOfErat1sthenes(int n, vll &pri) 
{ 
    vb prime(n+1, true); 
   
    for (int p=2; p*p<=n; p++) 
    { 
        
        if (prime[p] == true) 
        { 
            pri.pb(p);
            
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}

ll mo(ll a)
{
    return a%MOD;
}

bool compare(pll a, pll b)
{
    return a.first>b.first;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin>>n>>m;

    vvll gr(n+1);
    vll towards(n+1, 0);

    for(ll i=0;i<m;i++)
    {
        ll a, b;
        cin>>a>>b;

        gr[a].pb(b);
        towards[b]++;
    }

    vll dp(n+1, 0);
    queue<ll> beg;

    for(ll i=1;i<=n;i++) if(!towards[i]) beg.push(i);

    while(!beg.empty())
    {
        ll f = beg.front();
        beg.pop();

        for(ll ele: gr[f])
        {
            dp[ele] = max(dp[ele], dp[f]+1);
            towards[ele]--;
            if(!towards[ele]) beg.push(ele);
        }
    }

    ll ans = *max_element(dp.begin(), dp.end());
    cout<<ans<<"\n";

    return 0;
}
