//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int N = 10;
const int X = 1<<8;

//head

int n, a[3];
int l[N];
int dp[3][X];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a[0] >> a[1] >> a[2];
  rep(i, n) cin >> l[i];

  rep(u, 3) {
    rep(i, 1<<n) {
      if(!i) dp[u][i] = INF;
      else {
        int sum = 0;
        int cnt = 0;
        rep(j, n) if(i>>j&1) {
          sum += l[j];
          cnt++;
        }
        dp[u][i] = 10*(cnt-1) + abs(sum-a[u]);
      }
    }
    rep(i, n) rep(j, 1<<n) {
      if(j>>i&1) chmin(dp[u][j], dp[u][j^(1<<i)]);
    }
  }

  int ans = INF;
  rep(i, 1<<n) {
    int x = ((1<<n)-1)^i;
    for(int j = x; j > 0;) {
      j--;
      j &= x;
      int k = (1<<n)-1-i-j;
      chmin(ans, dp[0][i] + dp[1][j] + dp[2][k]);
    }
  }

  cout << ans << endl;
}