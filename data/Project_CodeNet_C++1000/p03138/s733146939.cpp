#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr ll INF = 1e16;
constexpr ll MOD = 1000000007;

#define rep(i, N) for(ll i=0; i<(N); ++i)

ll max(ll a, ll b) {return a < b ? b : a; }
ll min(ll a, ll b) {return a > b ? b : a; }
double maxf(double a, double b) { return a < b ? b : a; }

template<typename T> inline string toString(const T &a) {
  ostringstream oss; oss << a; return oss.str();
}

ll dp[61][2];

/* 二進数のbitsetに変換する */
//MSBが先頭に来る
int make_bitset(bitset<60>& bs, ll val) {
  /*int bit_digits = 0;
  int tval = val;
  while(tval) {
    tval /= 2;
    ++bit_digits;
  }*/
  int bit_digits = 60;
  
  int i = 1;
  while(true) {
    bs.set(bit_digits - i, val % 2);
    val /= 2;
    if(val == 0) break;
    ++i;
  }
  
  return bit_digits;
}

int main() {
  int N;
  ll K;
  
  cin >> N >> K;
  
  bitset<60> Kb;
  vector<bitset<60>> Ab(N);
  
  rep(i, 60) {
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  
  make_bitset(Kb, K);
  
  rep(i, N) {
    ll A;
    cin >> A;
    make_bitset(Ab[i], A);
  }
  
  // int bit_digits = 0;
  // ll tval = K;
  // while(tval) {
  //   tval /= 2;
  //   ++bit_digits;
  // }
  int bit_digits = 60;
  
  vector<int> bitcounts;
  
  rep(j, 60) {
    int ct = 0;
    rep(i, N) {
      if(Ab[i][j]) ++ct;
    }
    bitcounts.push_back(ct);
  }
  
  dp[60 - bit_digits][0] = 0;
  
  for(int i=60 - bit_digits; i<60; ++i) {
    rep(j, 2) {
      if(dp[i][j] >= 0) {
        rep(d, (j ? 1 : Kb[i]) + 1) {
          int i_n = i + 1;
          int j_n = j || d < Kb[i];
          ll n_v = dp[i][j] + (d == 0 ? ((ll)bitcounts[i] << (60-i-1)) : ((ll)(N - bitcounts[i]) << (60-i-1)));
          dp[i_n][j_n] = max(dp[i_n][j_n], n_v);
        }
      }
    }
  }
  
  cout << max(dp[60][0], dp[60][1]) << endl;
}
