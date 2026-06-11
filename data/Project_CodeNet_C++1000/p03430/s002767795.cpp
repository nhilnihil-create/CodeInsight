#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  string s; cin >> s;
  int k; cin >> k;
  string revs = s;
  reverse(ALL(revs));
  int n = SZ(s);
  vector<vvi> dp(n+1, vvi(n+1, vi(k+1, 0)));
  REP(i, n) {
    REP(j, n) {
      REP(l, k+1) {
        if(s[i] == revs[j]) {
          chmax(dp[i+1][j+1][l], dp[i][j][l] + 1);
        } else {
          chmax(dp[i+1][j+1][l], max(dp[i+1][j][l], dp[i][j+1][l]));
          if(l != k) chmax(dp[i+1][j+1][l+1], dp[i][j][l] + 1);
        }

        if(i<n && n-1-j >= 0 && s[i] == s[n-1-j]) {
          chmax(dp[i+1][j+1][k], dp[i][j][k] + 1);
        }
      }
    }
  }
/*
  REP(l, k+1) {
    REP(i, n) {
      REP(j, n) {
        cout << dp[i][j][l] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  */

  int ans = 0;
  REP(l, k+1) {
    REP(i, n+1) chmax(ans, dp[i][n-i][l] * 2);
    REP(i, n) chmax(ans, dp[i][n-i-1][l] * 2 + 1);
  }
  cout << ans << endl;

}






















