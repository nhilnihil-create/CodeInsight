#include <bits/stdc++.h>
using namespace std;


/* エイリアス */
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define endl '\n'

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define em emplace


/* 関数マクロ */
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n, m) for (ll i = n; i <= m; ++i)
#define rep3(i, n, m) for (ll i = n; i >= m; --i)
#define all(v) v.begin(), v.end()
#define si(v) int(v.size())
#define UNIQUE(v) sort(all(v)), v.erase(unique(all(v)),v.end())


/* 定数 */
const ll mod = 1e9 + 7;
const ll infll = (1LL << 62) - 1;
const ll inf = (1LL << 30) - 1;


/* その他 */
template<class S, class T> inline bool chmax(S &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


signed main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  
  int n; cin >> n;
  vi left(n+1, 0), right(n+1, 0), a(n);

  rep(i, n) cin >> a[i];
  rep(i, n) left[i+1] = __gcd(left[i], a[i]);

  reverse(all(a));

  rep(i, n) right[i+1] = __gcd(right[i], a[i]);

  int ans = 1;
  rep(i, n+1) chmax(ans, __gcd(left[i], right[n-i-1]));

  cout << ans << endl;
}