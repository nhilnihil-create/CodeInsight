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

    vvll dp(k+1, vll(n+1)), mat(k+1, vll(n+1));
    vll sum(n+1, 0);
    sort(a.begin(), a.end(), greater<ll>());

    for(ll i=1;i<=n;i++)
    {
        sum[i] = sum[i-1] + a[i-1];
    }

    for(ll i=0;i<=n;i++) dp[0][i] = 1;
    for(ll i=0;i<=n;i++) mat[0][i] = 1;
    for(ll i=0;i<=k;i++) mat[i][0] = 1;
    //for(ll i=1;i<=k;i++) dp[i][0] = i;
 
    for(ll i=1;i<=k;i++)
    {
        for(ll j=1;j<=n;j++)
        {

            if(sum[j]>=i)
            {
                dp[i][j] = mo(mo(mat[i][j-1]) - mo(((i-a[j-1]-1>=0)?mat[i-a[j-1]-1][j-1]:0)) + MOD);
            }
          
            mat[i][j] = mo(mo(dp[i][j]) + mo(mat[i-1][j]));
            // for(ll l=i;l>=max(0LL, i-a[j-1]); l--)
            // {
            //     dp[i][j] = mo(mo(dp[i][j]) + mo(dp[l][j-1])); 
            // }
        }
    }

    // cout<<"sum: ";
    // show(sum);

    // for(ll i=0;i<=k;i++)
    // {
    //     for(ll j=0;j<=n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    if(sum[n]<k) dp[k][n] = 0;

    cout<<dp[k][n]<<"\n";

    return 0;
}
