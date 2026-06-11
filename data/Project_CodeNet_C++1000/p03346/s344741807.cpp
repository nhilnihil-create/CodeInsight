#include <iostream>

using namespace std;
const int MAXN = 1e5 * 2 + 10;

int n;
int p[MAXN];
int dp[MAXN];

void solve() {
  int maxSequence = 0;
  for (int i=0;i<n;i++) {
    dp[p[i]] = dp[p[i] - 1] + 1;
    maxSequence = max(maxSequence, dp[p[i]]);
  }
  cout << n - maxSequence << endl;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> p[i];
  }
  solve();
}
