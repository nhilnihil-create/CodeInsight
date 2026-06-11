//#include<bits/stdc++.h>
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

    ll n, k;
    cin>>n>>k;

    vll a(n);
    enter(a);

    vvll dp(n+1, vll(k+1, 0));

    for(ll i=0;i<=n;i++) dp[i][0] = 1;

    for(ll i=1;i<=n;i++)
    {
        vll pre(k+1);
        pre[0] = dp[i-1][0];
        for(ll j=1;j<=k;j++)
        {
            pre[j] = mo(mo(pre[j-1]) + mo(dp[i-1][j]));
        }

        // cout<<"pre: "<<i<<": ";
        // show(pre);
        // cout<<"a[i-1]:"<<a[i-1]<<"\n";

        for(ll j=1;j<=k;j++)
        {
            dp[i][j] = mo(mo(pre[j]) - mo(((j-a[i-1]-1)>=0?pre[j-a[i-1]-1]:0)) + MOD);
        }

    }

    // for(ll i=0;i<=n;i++)
    // {
    //     for(ll j=0;j<=k;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<dp[n][k]<<"\n";

    return 0;
}
