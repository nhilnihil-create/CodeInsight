#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
#define VAR(type,...) type __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);each(x, name)in(x)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

string nth(set<string> &st, int n) {
  int i = 0;
  each(x, st) {
    if (i++ == n) {
      return x;
    }
  }
  return "";
}

void solve() {
  VAR(string, s);
  VAR(int, K);
  set<string> st;

  int sl = s.length();
  rep(i, 0, sl) {
    if ((int)st.size() >= K) {
      auto ss = nth(st, K - 1);
      if (s.substr(i, ss.size()) >= ss) {
        continue;
      }
    }
    rep(j, 1, sl + 1 - i) {
      st.insert(s.substr(i, j));
    }
  }
  print(nth(st, K - 1));
}
