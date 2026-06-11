#include <bits/stdc++.h>
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)
using namespace std;
using ll = long long;

// DP 実装の順序
// DP 配列全体を「DP の種類に応じた初期値」で初期化
// 初期条件を入力
// ループを回す
// テーブルから解を得て出力

// 初期化
const ll INF = 1LL << 60;
const ll DP_MAX = 1e5 + 10;
ll dp[DP_MAX];
ll s[DP_MAX];

int N;
void input() {
  rep(i, 0, DP_MAX) dp[i] = INF;
  dp[0] = 0;
  cin >> N;
  rep(i, 0, N) cin >> s[i];
}

// ループ
// chmin(dp[なにか], dp[なにか] + なにか);
void solve() {
  rep(i, 0, N) {
    // 1つ前からの遷移
    chmin(dp[i], dp[i - 1] + abs(s[i] - s[i - 1]));
    // 2つ前からの遷移
    if (i > 1) chmin(dp[i], dp[i - 2] + abs(s[i] - s[i - 2]));
  }
  // 解を得て出力
  cout << dp[N - 1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}