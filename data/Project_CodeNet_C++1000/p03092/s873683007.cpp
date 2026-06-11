#include <bits/stdc++.h>
using namespace std;
#define _MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) _MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define pb push_back
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.first<<","<<p.second<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}
#else
#define dbg(...) {}
#endif

const long INF = 1L<<60;

long dp[500005];

int main(){
  int n;
  long a,b;
  cin>>n>>a>>b;
  vector<int> v(n);
  rep(i,n) cin>>v[i];

  fill(dp, dp+n+2, INF);
  dp[0] = 0;

  rep(i,n) rep(j,n+1) if(dp[j]< INF && j != v[i]){
    if(j < v[i]){
      dp[v[i]] = min(dp[v[i]], dp[j]);
      dp[j] += a;
    } else {
      dp[j] += b;
    }
  }

  long ans = INF;
  rep(i,n+1) ans = min(ans, dp[i]);

  cout << ans << endl;

  return 0;
}
