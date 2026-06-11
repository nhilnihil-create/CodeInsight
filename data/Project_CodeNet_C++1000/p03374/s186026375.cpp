//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define PI          3.1415926535897932384626433832795l

#define pb push_back
#define mp make_pair
#define lb lower_bound // First element which is not less than val
#define ub upper_bound // First element greater than val
#define f first
#define s second

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define endl '\n'
#define re return
#define repz(i, a) for (ll i = 0; i < (a); i++)
#define vecin(n,v) for(ll i = 0; i < n; i++) cin>>v[i];
#define full(v) v.begin(),v.end()

void solve()
{
  ll n,c;
  cin >> n >> c;
  vll x(n+1);
  vll v(n+1);

  for (int i =1; i <= n; i++)
  {
    cin >> x[i] >> v[i];
  }

  ll dp[n][2];
  memset(dp,0,sizeof(dp));
  ll curr = 0;
  for (int i = 1; i <= n; i++)
  {
    curr += v[i];
    dp[i][0] = max(dp[i-1][0],curr-x[i]);
    dp[i][1] = max(dp[i-1][1],curr-x[i]*2);
  }

  ll ans = dp[n][0];
  curr =0;

  for (int i = n; i > 0; i--)
  {
    curr += v[i];
    ans = max(ans,curr+dp[i-1][0] - (c-x[i])*2);
    ans = max(ans,curr+dp[i-1][1] - (c-x[i]));
  }

  cout << ans << endl;
  
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t = 1;
  //cin >> t;
  while (t--)
  {
    solve();
  }
}

