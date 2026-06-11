#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

const int MAX_N = 1e5+3;
const ll INF = 1LL << 60;
ll dp[MAX_N];

int main() {
  int n;
  cin >> n;

  rep(i,MAX_N) dp[i] = INF;
  dp[0] = 0;
  for (int i=1; i<=n; ++i) {
    for (int pow6 = 1; pow6 <= i; pow6 *= 6) {
      chmin(dp[i], dp[i-pow6] + 1);
    }
    for (int pow9 = 1; pow9 <= i; pow9 *= 9) {
      chmin(dp[i], dp[i-pow9] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
