#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int func(int n){
  if(n % 2 == 0)
    return n / 2;
  else
    return n * 3 + 1; 
}

int main() {
  int n, T;
  cin >> n >> T;
  int res = INF;
  rep(i, n){
    int c, t;
    cin >> c >> t;
    if(t > T) continue;
    chmin(res, c);
  }
  if(res == INF) cout << "TLE" << ln;
  else cout << res << ln;
  }
