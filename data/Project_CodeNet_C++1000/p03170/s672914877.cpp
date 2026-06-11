

/* Don't try to copy it!
                    nhi too,
                         goli maar ke cheed bana dunga...;););)
 
                 
    _/﹋\_
    (҂`_´)
    <,︻╦╤─҉- - - - - - - - => - => - =>
    _/﹋\_
                
*/
 
#include "bits/stdc++.h"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define pb push_back
#define f(a) for(ll i = 0;i<a;i++)
#define rep(i,a,b) for(ll i = a;i<b;i++)
#define rrep(i,a,b) for(ll i = a;i>b;i--)
#define vll vector<ll>
#define T ll t; cin>>t; while(t--)
#define freeopen freopen("input.txt","r",stdin);
#define freeclose freopen("output.txt","w",stdout);
#define MOD 1000000007
using namespace std;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll n,k;
ll a[100005];
ll m;
ll dp[100005];
ll tarr(ll total)
{
    // cout<<total<<"\n";
    if(total==0)
        return 0;
    if(dp[total]!=-1)
        return dp[total];

    dp[total]=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]<=total)
            {
                if(tarr(total-a[i])==0)
                    dp[total]=1;
            }

        }
        return dp[total];
}



main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;

    f(n)
    cin>>a[i];

    ll tf;
    ll m=*min_element(a,a+n);
    tf=tarr(k);
    if(tf)
        cout<<"First";
    else
        cout<<"Second";
}

