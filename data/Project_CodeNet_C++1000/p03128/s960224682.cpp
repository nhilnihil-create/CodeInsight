#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

// computes whether s > t or not when s and t are regarded
// as numeric numbers
bool gt(string s, string t) {
  if(s.size() > t.size()) return true;
  if(s.size() < t.size()) return false;
  return s > t;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(m);
  rep(i, m) cin >> A[i];
  vector<int> K = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  // The dp[j] table is the strage of the solutions in the
  // case of being used j matches. The 'X' means there is no
  // solution at that case.
  vector<string> dp(n + 1, "X");

  dp[0] = "";    // when we use 0 matches, we CAN make the
                 // empty sequence.

  for(int j = 1; j <= n; j++) {
    rep(i, m) {
      int k = K[A[i]];
      if(j - k < 0) continue;
      if(dp[j - k] == "X") continue;
      char c = '0' + A[i];
      string s = dp[j - k] + c;
      if(dp[j] == "X" || gt(s, dp[j])) {
        dp[j] = s;
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}