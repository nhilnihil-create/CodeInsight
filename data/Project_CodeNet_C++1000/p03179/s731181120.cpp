#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
template <class T> bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T> using v = vector<T>;
using P = pair<int, int>;

/*
 *  */

const int mod = 1e9 + 7;

signed main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  v<v<int>> dp(n, v<int>(n));
  rep(i, 0, n) dp[0][i] = 1;
  rep(i, 1, n){
    v<int> sum(n+1);
    rep(j, 0, n) sum[j+1] = (sum[j] + dp[i-1][j])%mod;
    if(s[i-1] == '<'){
      rep(j, 0, n-i) dp[i][j] = sum[j+1];
    }else{
      rep(j, 0, n-i) dp[i][j] = (sum[n-i+1]-sum[j+1]+mod)%mod;
    }
  }

  cout << dp[n-1][0] << endl;

//  rep(i, 0, n+1){
//    rep(j, 0, n-i) cout << dp[i][j] << " ";
//    cout << endl;
//  }

  return 0;
}
