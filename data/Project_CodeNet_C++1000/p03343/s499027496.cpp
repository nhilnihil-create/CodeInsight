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
  int n,k,q;
  cin >> n >> k >> q;
  vi a(n);
  vecin(n,a);

  int ans = 1e9;
  for (int x : a)
  {
    vi store;
    multiset<int> m;
    for (int i = 0; i <= n; i++)
    {
        if (i == n || a[i] < x)
        {
          sort(full(store));
          for (int j = 0; j <= (int)store.size()-k; j++)
            m.insert(store[j]);
          store.clear();
        }
        else
          store.pb(a[i]);
    }
    if ((int)m.size() < q)
      continue;
    auto it = m.begin();
    for (int i = 0; i < q-1; i++)
      it++;
    ans = min(ans,*it-x);
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

