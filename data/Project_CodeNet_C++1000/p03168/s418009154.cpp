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
const int INF = 0xccccccc;
const ll LINF = 922337203685477580LL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int N = 3910;

//head

int n;
ld dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  dp[0] = 1;
  cin >> n;
  rep(i, n) {
    ld p;
    cin >> p;
    for(int j = n; j > 0; j--) {
      dp[j] += dp[j-1] * p;
      dp[j-1] *= (1-p);
    }
  }

  cout << fixed << setprecision(20) << accumulate(dp+n/2+1, dp+n+1, 0.0) << endl;
}