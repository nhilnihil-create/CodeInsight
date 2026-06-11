#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define Debug(X) cout << #X << " = " << X << '\n'
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;

ll a[maxn], b[maxn], c[maxn];
int x, y, z, k;

bool ok(ll mid){
  int cnt = 0;
  For(i, 1, x)
    For(j, 1, y)
      For(t, 1, z){
        if (a[i] + b[j] + c[t] < mid) break;
        ++cnt;
        if (cnt >= k) return true;
      }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
  cin >> x >> y >> z >> k;
  For(i, 1, x) cin >> a[i];
  For(i, 1, y) cin >> b[i];
  For(i, 1, z) cin >> c[i];

  sort(a + 1, a + x + 1, greater<ll>());  sort(b + 1, b + y + 1, greater<ll>());  sort(c + 1, c + z + 1, greater<ll>());

  ll l = a[x] + b[y] + c[z], r = a[1] + b[1] + c[1];

  while (l <= r){
    ll mid = (l + r) >> 1;
    if (ok(mid)) l = mid + 1;
    else r = mid - 1;
  }
  ll ans = l - 1;
//  cout << ans << '\n';
  vector<ll> res1, res2;
  int cnt = 0;

  For(i, 1, x)
    For(j, 1, y)
      For(t, 1, z){
        if (a[i] + b[j] + c[t] < ans) break;
        if (a[i] + b[j] + c[t] == ans && sz(res1) < k) res1.push_back(a[i] + b[j] + c[t]);
        if (a[i] + b[j] + c[t] > ans) res2.push_back(a[i] + b[j] + c[t]);
        if (sz(res2) >= k) {
          i = x; j = y; t = z;
        }
      }
  sort(All(res2), greater<ll>());
  for (auto val : res2) cout << val << '\n';
  For(i, 1, k - sz(res2)) cout << ans <<'\n';
return 0;
}

