#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  string s; cin >> s;

  vvll dp(n, vll(n, 0));
  for(int i=0;i<n;++i) {
    dp[0][i] = 1;
  }

  for(int i=0;i<n-1;++i) {
    vll su(n+1, 0);
    for(int j=0;j<n;++j) {
      su[j+1] = su[j] + dp[i][j];
      su[j+1] %= MOD;
    }

    if(s[i] == '<') {
      for(int j=0;j<n;++j) {
        dp[i+1][j] = (su[n] + MOD - su[j+1]) % MOD;
      }
    } else {
      for(int j=0;j<n-i-1;++j) {
        dp[i+1][j] = (su[j+1] + MOD - su[0]) % MOD;
      }
    }
    

/*     for(int j=0;j<n;++j) {
      if(s[i] == '<') {
        for(int k=0;k<j;++k) {
          dp[i+1][k] += dp[i][j];
          dp[i+1][k] %= MOD;
        }
      } else {
        for(int k=j;k<n-i-1;++k) {
          dp[i+1][k] += dp[i][j];
          dp[i+1][k] %= MOD;
        }
      }
    } */
  }

  ll ans = 0;
  for(int i=0;i<n;++i) {
    ans += dp[n-1][i];
    ans %= MOD;
  }
  cout << ans << endl;

}
