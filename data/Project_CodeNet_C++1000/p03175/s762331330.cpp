//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
/*
    I LOVE CLARICE STARLING

     ♥LOVE♥        ♥LOVE♥
  ♥LOVE♥♥LOVE♥  ♥LOVE♥♥LOVE♥
♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
   ♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
      ♥LOVE♥♥LOVE♥♥LOVE♥
         ♥LOVE♥♥LOVE♥
            ♥LOVE♥
               ♥


    EXPLAINATION BELOW->
    Dp on trees+pnc
   
*/
//
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mii;
#define MOD7 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define Test_cases ll TC;cin>>TC;while(TC--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define sp(x) fixed<<setprecision(x)
#define sz(x) (ll)(x.size())
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
int n;
vector<vector<int>>adj;
vector<vector<ll>>dp;
void dfs(int v,int p=-1)
{
    ll ans_w,ans_b;ans_b=ans_w=1ll;
    for(auto it:adj[v])
    {
        if(it!=p)
        {
            dfs(it,v);
            ans_w=((ans_w)*((dp[it][1]+dp[it][0])%MOD7))%MOD7;
            ans_b=(ans_b*dp[it][1])%MOD7;
        }
    }
    dp[v][0]=ans_b;dp[v][1]=ans_w;
}
void solve()
{
  cin>>n;
  adj=vector<vector<int>>(n);
  dp=vector<vector<ll>>(n+1,vector<ll>(2,0));
  int i,u,v;
  fo(i,0,n-1)
  {
      cin>>u>>v;u--;v--;
      adj[u].pb(v);adj[v].pb(u);
  }
  dfs(0);
  ll ans=(dp[0][0]+dp[0][1])%MOD7;
  cout<<ans<<"\n";
}
int main()
{
   fastio
   solve();
  return 0;
}
//map<ll,ll,greater<int>> to sort in descending order ,in iterator declaration no greater<int>
//if you want to apply lowerbound on set use s.lower_bound(key),not the one used for vector
/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
