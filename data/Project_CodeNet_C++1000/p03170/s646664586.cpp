#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 105, K = 100005;

int n, k, a[N];

int dp[K];

int rec(int i) {
  if (dp[i] != 0) return dp[i];
  int res = -1;
  rep(ai, n) {
    if (i - a[ai] < 0) continue;
    if (rec(i - a[ai]) == -1) res = 1;
  }
  return dp[i] = res;
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  rep(i, k+1) dp[i] = 0;
  if (rec(k) == 1) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}