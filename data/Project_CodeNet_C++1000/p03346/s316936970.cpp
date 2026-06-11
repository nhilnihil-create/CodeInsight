#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 2e5 + 10;
int a[N];
int pre[N], suf[N];
int mx[N], mn[N];
int pos[N], len[N];

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }

  pre[1] = pos[1] == 1 ? 0 : 1;
  for (int i = 1; i <= n; i++) {
    mx[i] = max(mx[i - 1], a[i]);
  }
  for (int x = 2; x <= n; x++) {
    if (mx[pos[x]] > x) {
      pre[x] = x;
    } else {
      pre[x] = pre[x - 1];
    }
  }

  suf[n] = pos[n] == n ? 0 : 1;
  mn[n + 1] = 1e8;
  for (int i = n; i >= 1; i--) {
    mn[i] = min(mn[i + 1], a[i]);
  }

  for (int x = n - 1; x >= 1; x--) {
    if (mn[pos[x]] < x) {
      suf[x] = n - x + 1;
    } else {
      suf[x] = suf[x + 1];
    }
  }

  int ans = n;
  for (int i = 1; i < n; i++) {
    ans = min(ans, suf[i + 1] + pre[i]);
  }
  ans = min({ans, pre[n], suf[1]});

  len[n] = 1;
  for (int i = n - 1; i > 1; i--) {
    if (pos[i + 1] > pos[i]) {
      len[i] = 1 + len[i + 1];
    } else {
      len[i] = 1;
    }
    ans = min(ans, pre[i - 1] + suf[i + len[i]]);
  }

  cout << ans << endl;

  return 0;
}
