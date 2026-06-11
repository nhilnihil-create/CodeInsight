// https://atcoder.jp/contests/abc106/tasks/abc106_b

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
#define all(x) (x).begin(), (x).end()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end());
const long long INF = 1LL << 60;
// map<int,int> mp;

bool solve(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    // cout << n % i << endl;
    if (n % i == 0) cnt += 1;
  }

  if (cnt == 8 && n % 2 == 1) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int N, ans = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (solve(i) == true) ans += 1;
  }
  cout << ans << endl;
  return 0;
}