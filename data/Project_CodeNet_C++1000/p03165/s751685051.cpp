#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

// 入力
string s,t;

// DP テーブル
long long dp[3010][3010] = {}; //共通文字列の長さ、初期値も初期条件も0

int main() {
  
  cin >> s >> t;

  // ループ
  FOR(i,0,s.size()) {
    FOR(j,0,t.size()) {
      if (s[i] == t[j]) { //共通部分文字列を増やせる時
        chmax(dp[i+1][j+1], dp[i][j] + 1);
      }
      chmax(dp[i+1][j+1], dp[i+1][j]);
      chmax(dp[i+1][j+1], dp[i][j+1]);
    }
  }
  
  // 答え(復元)
  string ans = "";
  int i = s.size();
  int j = t.size();
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i-1][j]) { //上から来てた時
      i--; //ansには何も付け加えず、遷移元を探る
    }
    else if (dp[i][j] == dp[i][j-1]) { //左から来てた時
      j--;
    }
    else {
      ans = s[i-1] + ans; //t[j-1]でもOK
      i--; j--;
    }
  }
  cout << ans << endl;
 
}