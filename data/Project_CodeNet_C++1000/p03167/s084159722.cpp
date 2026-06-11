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

    ll h, w;
    cin>>h>>w;

    vvll mat(h, vll(w));

    for(ll i=0;i<h;i++)
    {
        for(ll j=0;j<w;j++)
        {
            char ch;
            cin>>ch;

            if(ch=='.') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }

    vvll ans(h, vll(w));

    if(mat[0][0]) ans[0][0] = 1;

    for(ll i=1;i<w;i++) if(mat[0][i]) ans[0][i] = ans[0][i-1];
    for(ll i=1;i<h;i++) if(mat[i][0]) ans[i][0] = ans[i-1][0];

    for(ll i=1;i<h;i++)
    {
        for(ll j=1;j<w;j++)
        {
            if(mat[i][j]) 
            {
                ans[i][j] = mo(mo(ans[i-1][j]) + mo(ans[i][j-1]));
            }
        }
    }

    cout<<ans[h-1][w-1]<<"\n";

    return 0;
}
