#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

int main() {
  //https://atcoder.jp/contests/abc076/tasks/abc076_c
  string r,t; cin >> r >> t;
  string rr(r);
  string s;
  int n=r.size(), m=t.size();
  bool un = true;
  rep(i,n-m+1) {
    bool ok = true;
    rep(j,m) {
      if(r[i+j] == '?') continue;
      if(r[i+j] == t[j]) continue;
      ok=false;
      break;
    }
    if(ok) {
      string ss(r);
      rep(k, n) {
        if(k<i) ss[k] = rr[k];
        else if(k<i+m) ss[k] = t[k-i];
        else if(rr[k]=='?') ss[k] = 'a';
        else ss[k] = rr[k];
      }
      if(un) s=ss;
      else umin(s, ss);
      un=false;
    }
    if(rr[i]=='?') rr[i] = 'a';
  }
  if(un) puts("UNRESTORABLE");
  else cout << s << endl;
}
