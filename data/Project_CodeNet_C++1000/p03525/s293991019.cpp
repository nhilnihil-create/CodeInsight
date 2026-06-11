// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
// #define int long long
const int INF=1e9;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
  #define cerrendl 42
#endif
//}}}


signed main() {
  int n;cin>>n;
  if (n>=24){
    cout << 0 << endl;
    return 0;
  }

  vi d(n);
  vector<int> cnt(15);
  int mcnt = 0;
  rep(i, n){
    cin>>d[i];
    cnt[d[i]]++;
    chmax(mcnt, cnt[d[i]]);
  }
  dump(d);
  if (n>=13){
    // mind = 2は無理
    // mind = 1が達成可能かどうか
    // 重なっている点がないかどうか
    // d[i]で同一のものが３点以上あるとだめ
    if (mcnt>=3 || cnt[0]>=1){
      cout << 0 << endl;
    }
    else{
      cout << 1 << endl;
    }

    return 0;
  }


  int ans = 0;
  rep(mask, 1<<n){
    vector<int> exist(n+1, 0);
    rep(i, n){
      if (mask&(1<<i)){ exist[i+1] = d[i]; }
      else{ exist[i+1] = 24-d[i]; }
    }
    sort(all(exist));

    int mind = INF;
    rep(u, sz(exist)){
      int v = (u+1)%sz(exist);
      int d = abs(exist[u]-exist[v]);
      chmin(mind, min(d, 24-d));
      if (mind<ans) break;
    }
    chmax(ans, mind);
  }
  cout << ans << endl;

  return 0;
}
