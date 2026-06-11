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
  int n;
  cin >> n;
  vll a(n), b(n);
  
  repz(i,n)
    cin >> a[i] >> b[i];


  ll sum1 = 0, sum2 =LLONG_MAX;
  for (int i = 0; i < n; i++)
  {
    sum1 += a[i];
    if (a[i] > b[i])
      sum2 = min(sum2,b[i]);
  }

  if (sum2 == LLONG_MAX)
    sum2 = sum1;
  cout << sum1-sum2 << endl;
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

