#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string MINUSINF = "-";

void chmax(string &a, string b) {
  if (a == MINUSINF) { a = b; }
  else if (a.size() < b.size()) { a = b; }
  else if (a.size() == b.size()) {
    if (a < b) { a = b; }
  }
}

long long match[10] = {2,5,5,4,5,6,3,7,6};
// dp[i] := マッチ棒をちょうどi本使って作れる数値の最大値
// dp[i+match[a]] = max(dp[i+match[a], dp[i]*10 + a) と遷移
string dp[10100];

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);

  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < 10100; i++) { dp[i] = MINUSINF; }

  dp[0] = "";
  for (int i = 0; i <= n; i++) {
    if (dp[i] == MINUSINF) { continue; }
    for (auto aa : a) {
      chmax(dp[i+match[aa-1]], dp[i] + (char)('0' + aa));
    }
  }
  cout << dp[n] << endl;
}