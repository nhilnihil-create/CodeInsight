// template version 1.7

// varibable settings {{{
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define int long long
#define INF 1e18
// #define INF 2147483647
#define MOD 1e9+7
#define infile "../test/sample-1.in"
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
#define fi first
#define se second

// }}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)(b-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;

// dump macro
#ifdef PCM
  #include "dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
// }}}

int solve(){
  int n;cin>>n;
  int t[n];
  int v[n];
  int s = 0;
  rep(i, n){
    cin>>t[i]; 
    s += t[i];
  }
  rep(i, n){ cin>>v[i]; }

  vi upper(2*s+1, INF);
  int time=0;
  rep(i, n){
    rep(j, (2*t[i])+1){
      chmin(upper[time], v[i]);
      if (j!=(2*t[i]))time++;
    }
  }
  // dump(sz(upper), upper);

  vector<double> res(2*s+1);

  double sp=0;
  res[0]=0;
  rep(i, 1, (2*s)+1){
    if (sp<upper[i]) sp+=0.5;
    if (sp>upper[i]) sp=upper[i];
    res[i]=sp;
  }
  // dump(res);

  sp=0;
  res[2*s]=0;
  rrep(i, 0, 2*s){
    if (sp<upper[i]) sp+=0.5;
    if (sp>upper[i]) sp=upper[i];
    chmin(res[i], sp);
  }
  // dump(res);

  double ans=0;
  rep(i, 2*s){
    ans += (res[i]+res[i+1])/4.0;
  }
  printf("%.4f", ans);

  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
