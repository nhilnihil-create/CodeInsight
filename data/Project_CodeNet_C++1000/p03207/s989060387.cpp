#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  int p;
  int max_p;
  rep(i, N) {
    cin >> p;
    ans += p;
    max_p = max(p, max_p);
  }
  cout << ans - max_p / 2 << endl;
  return 0;
}