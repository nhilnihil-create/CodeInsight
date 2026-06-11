#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
	  for(auto &e:u) fill_v<T>(e,v...);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  int64 K;
  cin >> s >> K;
  auto dp = make_v<int64>(s.size()+1, s.size()+1, K+1); // [l, r]で作れるアの最大値
  REP(k, K+1) {
    REP(w, s.size()) {
      REP(l, s.size() - w) {
        int64 r = l + w;
        if (k+(s[l] != s[r]) <= K) {
          if (l == r)
            chmax(dp[l][r][k + (s[l] != s[r])], 1);
          else
            chmax(dp[l][r][k + (s[l] != s[r])], dp[l+1][r-1][k] + 2);
        }
        if (l+1 <= s.size())
          chmax(dp[l][r][k], dp[l+1][r][k]);
        if (r-1 >= 0)
          chmax(dp[l][r][k], dp[l][r-1][k]);
      }
    }
  }
  int64 res = 0;
  REP(i, s.size()) {
    REP(j, s.size()) {
      REP(k, K+1) {
        chmax(res, dp[i][j][k]);
      }
    }
  }
  cout << res << endl;
}
