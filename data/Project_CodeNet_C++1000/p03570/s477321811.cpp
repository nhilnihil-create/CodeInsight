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
typedef vector<vector<ll>> matrix;

int dp[1<<26];
void solve() {
  string s;
  cin >> s;
  for(int i = 1; i < (1<<26); i++) dp[i] = 1 << 25;
  int curr = 0;
  for(int i = 0; i < s.size(); i++) {
    curr ^= 1 << (s[i] - 'a');
    for(int x = 0; x < 26; x++) {
      dp[curr] = min(dp[curr], 1 + dp[curr ^ (1<<x)]);
    }
  }
  cout << max(1, dp[curr]) << "\n";
}

void casesolve() {
  int t;
  cin >> t; cin.ignore();
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
