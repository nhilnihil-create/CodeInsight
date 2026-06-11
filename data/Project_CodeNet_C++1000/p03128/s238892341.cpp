#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
const ll INFll = 1ll << 60;
const string MINUSINF = "-";

void chmax(string &a, string b) {
  if (a == MINUSINF)
    a = b;
  else if (a.size() < b.size())
    a = b;
  else if (a.size() == b.size()) {
    if (a < b) a = b;
  }
}

long long match[10] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

string dp[11000];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) cin >> a[i];

  for (int i = 0; i < 11000; i++) dp[i] = MINUSINF;

  dp[0] = "";
  for (int i = 0; i <= n; i++) {
    if (dp[i] == MINUSINF) continue;
    for (auto a_i : a) chmax(dp[i + match[a_i - 1]], dp[i] + (char)('0' + a_i));
  }

  cout << dp[n] << endl;
  return 0;
}
