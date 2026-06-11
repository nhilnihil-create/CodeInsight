#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <deque>     // deque
#include <iomanip>   //setprecsion
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <utility>   // pair, make_pair
#include <vector>    // vector

#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>  //sin, cos, tan

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q, r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;
typedef vector<tuple<ll, ll, ll>> vtlll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
  cout << a << endl;
  exit(0);
}

void Main()
{
  ll n; cin >> n;
  vll v(n); rep(i, n) cin >> v[i];
  map<ll, ll> up, down;
  vll key_up, key_down;
  for(ll i = 0;i < n;i += 2)
  {
    if(!up.count(v[i]))
    {
      key_up.pb(v[i]);
    }
    up[v[i]]++;
  }
  for(ll i = 1;i < n;i += 2)
  {
    if(!down.count(v[i]))
    {
      key_down.pb(v[i]);
    }
    down[v[i]]++;
  }
  vpll a, b;
  rep(i, key_up.size())
  {
    a.pb(mp(up[key_up[i]], key_up[i]));
  }
  if(key_up.size() == 1) a.pb(mp(0, -1));
  sort(all(a)), reverse(all(a));
  rep(i, key_down.size())
  {
    b.pb(mp(down[key_down[i]], key_down[i]));
  }
  if(key_down.size() == 1) b.pb(mp(0, -2));
  sort(all(b)), reverse(all(b));
  ll ans = 0;
  if(a[0].second != b[0].second)
  {
    fin(n / 2 - a[0].first + n / 2 - b[0].first);
  }
  else
  {
    //cout << a[0].first << " " << b[1].first  << " " << a[1].first << " " << b[0].first << endl;
    fin(min(n / 2 - a[0].first + n / 2 - b[1].first, n / 2 - a[1].first + n / 2 - b[0].first));
  }  
}

//前処理
int main()
{
  //ios::sync_with_stdio(false);
  //cin.tie(0);
  cout << fixed << setprecision(20); //高精度少数表示
  //cout << setfill('0') << internal << setw(4); 0埋め４桁
  Main();
  return 0;
}
