#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x);
  vector<ll> b(x);
  vector<ll> c(x);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  SORT(a);
  SORT(b);
  SORT(c);
  RSORT(a);
  RSORT(b);
  RSORT(c);
  vector<ll> ans;
  for (int i = 0; i < x; i++) {
    if (i > k) break;
    for (int j = 0; j < y; j++) {
      if (i * j > k) break;
      for (int t = 0; t < z; t++) {
        if (i * j * t > k) break;
        ans.push_back(a[i] + b[j] + c[t]);
      }
    }
  }
  SORT(ans);
  RSORT(ans);
  for (int i = 0; i < k; i++) {
    cout << ans[i] << endl;
  }
}