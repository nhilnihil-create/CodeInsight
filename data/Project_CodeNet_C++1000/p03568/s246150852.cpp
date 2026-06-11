#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int ans = 0;

void rec(vector<int> a, int cur) {
  if (cur == n) {
    int p = 1;
    for (int i = 0; i < n; ++i) {
      p *= a[i];
    }
    if (p % 2 == 0) ans++;
    return;
  }

  rec(a, cur + 1);
  a[cur]++;
  rec(a, cur + 1);
  a[cur] -= 2;
  rec(a, cur + 1);
}

int main() {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  rec(a, 0);
  cout << ans << '\n';
  return 0;
}
