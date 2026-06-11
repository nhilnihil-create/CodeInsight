#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, m, n) for (int i = m; i <= n; ++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll x, y;

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> x >> y;
  if (x % y == 0) {
    cout << -1 << endl;
  }
  else cout << x << endl;
  return 0;
}