#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18 + 7

int n, a[303];
int cnt[4] = {0};

double dp[303][303][303];

double solve(int one, int two, int three) {
  int rem = one + two + three;
  if (rem == 0) {
    return 0;
  }
  double &res = dp[one][two][three];
  if (res != 0) return res;
  res = 0.0;
  if (three > 0) {
    res += solve(one, two + 1, three - 1) * (double)three / (double)rem;
  }
  if (two > 0) {
    res += solve(one + 1, two - 1, three) * (double)two / (double)rem;
  }
  if (one > 0) {
    res += solve(one - 1, two, three) * (double)one / (double)rem;
  }

  res += (double)n / (double)rem;
  return res;
}

signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
    cnt[a[i]] ++;
  }

  // memset(dp, -1, sizeof dp);
  double res = solve(cnt[1], cnt[2], cnt[3]);
  cout << fixed << setprecision(10);
  cout << res << endl;

  return 0;
}