#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> v;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v.emplace_back(b, a);
  }
  sort(v.begin(), v.end());
  int ans = 0, cur = 0;
  for (int i = 0; i < m; i++) {
    int b = v[i].first;
    int a = v[i].second;
    if (cur < a) {
      ans++;
      cur = b - 1;
    }
  }
  cout << ans << endl;

  return 0;
}