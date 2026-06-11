/* ****mittal21**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define endl        '\n'
#define pii         pair<long long int,long long int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
#define N  100005
ll dp[N][3];
std::vector<ll> a[N];
void dfs(ll node,ll par)
{
  dp[node][1]=1;
  dp[node][0]=1;
  for(auto i:a[node])
  if(i!=par)
  {
    dfs(i,node);
    dp[node][1]=(dp[node][1]*dp[i][0])%hell;
    dp[node][0]=(dp[node][0]*(dp[i][1]+dp[i][0])%hell)%hell;
  }
}
void solve()
{
   ll n;
   cin>>n;
   for(int i=1;i<n;i++)
   {
      ll x,y;
      cin>>x>>y;
      a[x].pb(y);
      a[y].pb(x);
   }
   dfs(1,0);
   cout<<(dp[1][0]+dp[1][1])%hell;
   return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcase=1;
    //cin>>testcase;
    while(testcase--)
    {
        solve();
    }
    return 0;
}