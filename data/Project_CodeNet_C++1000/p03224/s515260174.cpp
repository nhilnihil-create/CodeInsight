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

bool solve(int n){
  long l=1;
  while(l*(l+1)/2 < n) l++;

  if(l*(l+1)/2 != n) return false;

  cout << "Yes" << endl;

  cout << l+1 << endl;

  vector<vector<int>> vv(l+1);

  int last = 0;
  rep(i,l+1){
    cout << l;
    rep(j,i) {
      cout << " " << vv[j][i-1];
      vv[i].pb(vv[j][i-1]);
    }
    rep(j,i,l){
      cout << " " << ++last;
      vv[i].pb(last);
    }
    cout << "\n";
  }


  return true;
}

int main(){
  int n;
  cin>>n;

  if(!solve(n)) cout << "No" << endl;

  return 0;
}
