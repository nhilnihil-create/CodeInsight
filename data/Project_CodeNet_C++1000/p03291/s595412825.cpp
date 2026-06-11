#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

LL add(LL a, LL b) { return (a + b) % kMod; }
LL mul(LL a, LL b) { return (a * b) % kMod; }

int main() {
  string S; cin >> S;
  int L = S.size();
  LL total = 1;
  vector<map<char, LL>> dp(L + 1, map<char, LL>());
  for (int i = 0; i < L; ++i) {
    if (S[i] == 'A') {
      dp[i + 1]['a'] = add(dp[i]['a'], total);
      dp[i + 1]['b'] = dp[i]['b'];
      dp[i + 1]['c'] = dp[i]['c'];
    } else if (S[i] == 'B') {
      dp[i + 1]['a'] = dp[i]['a'];
      dp[i + 1]['b'] = add(dp[i]['b'], dp[i]['a']);
      dp[i + 1]['c'] = dp[i]['c'];
    } else if (S[i] == 'C') {
      dp[i + 1]['a'] = dp[i]['a'];
      dp[i + 1]['b'] = dp[i]['b'];
      dp[i + 1]['c'] = add(dp[i]['c'], dp[i]['b']);
    } else {  // ?
      dp[i + 1]['a'] = add(mul(dp[i]['a'], 3), total);
      dp[i + 1]['b'] = add(mul(dp[i]['b'], 3), dp[i]['a']);
      dp[i + 1]['c'] = add(mul(dp[i]['c'], 3), dp[i]['b']);
      total = mul(total, 3);
    }
  }
  cout << dp[L]['c'] << endl;
}
