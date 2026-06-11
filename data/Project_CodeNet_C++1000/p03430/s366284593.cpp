#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> ppiii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> query;

string s;
int dp[301][301][301];
bool seen[301][301][301];

int solve(int lhs, int rhs, int k) {
  if(lhs > rhs) return 0;
  if(lhs == rhs) return 1;
  if(seen[lhs][rhs][k]) return dp[lhs][rhs][k];
  seen[lhs][rhs][k] = true;
  dp[lhs][rhs][k] = max(solve(lhs+1, rhs, k), solve(lhs, rhs-1, k));
  if(s[lhs] == s[rhs]) dp[lhs][rhs][k] = max(dp[lhs][rhs][k], 2 + solve(lhs+1, rhs-1, k));
  else if(k > 0) {
    dp[lhs][rhs][k] = max(dp[lhs][rhs][k], 2 + solve(lhs+1, rhs-1, k-1));
  }
  return dp[lhs][rhs][k];
}

void solve() {
  cin >> s;
  int k;
  cin >> k;
  cout << solve(0, s.size()-1, k) << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
