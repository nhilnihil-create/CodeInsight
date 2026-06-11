#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

// #define rep(i,n) for(int i=0;i<(n);++i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _fromto2(i,n) for(int i=0;i<=(n);++i)
#define _fromto3(i,a,b) for(int i=(a);i<=(b);++i)
#define fromto(...) _overload3(__VA_ARGS__,_fromto3,_fromto2,)(__VA_ARGS__)

#define rrep(i,n) for(int i=(n);i>=0;--i)
const int MOD = 1e9+7;
const int INF = 1e9;
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

// debug
template<class T>ostream& operator<<(ostream& os,const vector<T>& vec){os<<"{";for(int i=0;i<vec.size();++i)os<<(i?", ":"")<<vec[i];os<<"}";return os;}
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>& rhs){os<<"("<<rhs.first<<", "<<rhs.second<<")";return os;}

#ifdef LOCAL
  void debug() {cerr << "\n";}
  template<class First> void debug(const First& first) {cerr<<first<<"\n";}
  template<class First, class... Rest> void debug(const First& first, const Rest&... rest) {cerr<<first<<",";debug(rest...);}
#else
  #define debug(...) 42
#endif


int main() {
  int M, K; cin >> M >> K;

  if (M == 1 && K == 1) {
    cout << "-1\n";
    return 0;
  }
  if (K == 0) {
    rep(i, 1 << M) {
      cout << (i?" ":"")<< i << " " << i;
    }
    cout << endl;
  } else {
    if (K > (1 << M) - 1) {
      cout << "-1\n";
    } else {
      // 構築できる
      cout << K;
      rep(i, 1 << M) {
        if (i == K)
          continue;
        cout << " " << i;
      }
      cout << " " << K;
      rrep(i, (1 << M)-1) {
        if (i == K)
          continue;
        cout << " " << i;
      }
      cout << "\n";
    }
  }

  return 0;
}
