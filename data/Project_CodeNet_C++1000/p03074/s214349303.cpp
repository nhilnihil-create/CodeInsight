#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> v;
  int now = 1;
  int cnt = 0;
  rep(i, n) {
    if (s[i] == (now + '0')) {
      ++cnt;
    } else {
      v.push_back(cnt);
      now = 1 - now;
      cnt = 1;
    }
  }
  if (cnt != 0) v.push_back(cnt);
  int V = v.size();
  if (V % 2 == 0) v.push_back(0);

  vector<int> a(V + 1);
  rep(i, V) a[i + 1] = a[i] + v[i];

  int ans = 0;
  for (int i = 0; i < V; i += 2) {
    int add = 2 * k + 1;
    int sum = a[min(i + add, V)] - a[i];
    ans = max(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
