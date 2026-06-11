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

// Implementation by AI.Cash
// All the leaves are at n,n+1,...
// Every segment is of the form [l,r)

void solve()
{
  int l;
  cin >> l;

  vpii edges;
  int curr =0;
  for (int i = 18; i >= 0; i--)
  {
    while (l >= curr + (1<<i))
    {
      edges.pb({19-i,curr});
      curr += (1<<i);
    }
  }

  cout << 20 << " " << edges.size() + 36 << "\n";

  for (int i = 1; i < 19; i++)
  {
    cout << i+1 << " " << i+2 << " " << 0 << endl;
    cout << i+1 << " " << i+2 << " " << (1<<(18-i)) << endl;
  }

  for (int i = 0; i < (int)edges.size(); i++)
  {
    cout << 1 << " " << edges[i].f+1 << " " << edges[i].s << endl;
  }

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

