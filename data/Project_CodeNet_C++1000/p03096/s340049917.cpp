#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

const long long MOD = 1000000007;
vector<int> places[210000]; // [i] は 色がiであるような数列の場所リスト
long long dp[210000];
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> c(N);
  rep(i, N) cin >> c[i];

  for (int i = 0; i < 210000; ++i) places[i].clear();
  rep(i, N) places[c[i]].push_back(i);

  dp[0] = 1;
  rep1(i, N) {
    add(dp[i], dp[i-1]);

    int color = c[i-1];
    int it = lower_bound(places[color].begin(), places[color].end(), i-1) - places[color].begin(); // 今のindexは同じ色で何番目か
    if(it > 0) {
      int j = places[color][it - 1]; // 前回出現した同じ色のindex
      if ((i-1) - j > 1) add(dp[i], dp[j+1]); // 同じ色が連続していなければ加算
    }
  }
  cout << dp[N] << endl;
}
