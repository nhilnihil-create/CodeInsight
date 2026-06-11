#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int M = 30;
long long get(int vk[], int idx, vector<int>& a, vector<int>& b) {
  long long res = 0;
  for (int u = 0; u < (int) a.size(); u++) {
    bool flag = true;
    for (int i = idx; i < M; i++) {
      if (!vk[i] && (a[u] & (1 << i))) flag = false;
    }
    if (flag) res += b[u];
  }
  return res;
}
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int vk[M];
  for (int i = 0; i < M; i++) {
    vk[i] = (1 & (k >> i));
  }
  vector<int> a(n), b(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    bool flag = true;
    for (int j = 0; j < M; j++) {
      if (!vk[j] && (a[i] & (1 << j))) flag = false;
    }
    if (flag) ans += b[i];
  }
  for (int i = 0; i < M; i++) {
    if (vk[i]) {
      vk[i] = 0;
      ans = max(ans, get(vk, i, a, b));
      vk[i] = 1;
    }
  }
  cout << ans << endl;
  return 0;
}