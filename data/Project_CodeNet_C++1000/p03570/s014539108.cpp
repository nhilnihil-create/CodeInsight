#include <bits/stdc++.h>
using namespace std;
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

int solve(string &s){
  int n = s.size();

  int mask = 0;
  map<int,int> pos;
  vector<int> dp(n+1, INF);
  pos[0] = 0;
  dp[0] = 0;
  rep(p,n){
    mask = mask ^ (1<<(s[p]-'a'));
    rep(i,26){
      int nm = mask^(1<<i);
      if(pos.count(nm)==0) continue;
      int x = pos[nm];//dbg(p,x,bitset<26>(nm),i);
      dp[p+1] = min(dp[x]+1, dp[p+1]);
    }
    if(pos.count(mask)){
      dp[p+1] = min(dp[pos[mask]], dp[p+1]);
    }
    pos[mask] = p+1;
  }
  // dbg(dp);
  return max(dp[n], 1);
}

int main(){
  string s;
  cin>>s;
  int r = solve(s);
  reverse(all(s));
  cout << min(r, solve(s)) << endl;

  return 0;
}
