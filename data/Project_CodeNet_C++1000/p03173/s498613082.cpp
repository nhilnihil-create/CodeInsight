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
    for(ll i=0;i<n;i++) cin>>ar[i];
}

void show(vll &a)
{
    ll n = a.size();
    for(ll i=0;i<n;i++) cout<<a[i]<<" ";
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

const ll maxn = 405;
const ll INF = 1e18 + 5;
ll dp[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vll a(n);
    enter(a);

    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j] = 0;
            }
            else
            {
                ll sum = 0;

                for(ll k = i; k<=j; k++) sum += a[k];

                dp[i][j] = INF;
                for(ll k=i;k<=j-1;k++)
                {
                    dp[i][j] =  min(dp[i][j], dp[i][k] + dp[k+1][j] + sum);
                }
            }
        }
    }

    cout<<dp[0][n-1]<<"\n";

    return 0;
}