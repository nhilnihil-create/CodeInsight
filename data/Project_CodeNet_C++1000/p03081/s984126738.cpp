#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
const int mod=1e9+7;

int main(){
  int n,q;cin>>n>>q;
  string s;cin>>s;
  char t[q],d[q];
  rep(i,q)cin>>t[i]>>d[i];
  int ok=-1;
  int ng=n;
  while(ng-ok>1){
    int mid=(ng+ok)/2;
    rep(i,q){
      if(s[mid]==t[i]){
        if(d[i]=='L')--mid;
        else ++mid;
      }
    }
    if(mid<0){
      ok=(ng+ok)/2;
    }
    else ng=(ng+ok)/2;
  }
  int lok=ok+1;
  ok=n;
  ng=-1;
  while(ok-ng>1){
    int mid=(ng+ok)/2;
    rep(i,q){
      if(s[mid]==t[i]){
        if(d[i]=='L')--mid;
        else ++mid;
      }
    }
    if(mid==n){
      ok=(ng+ok)/2;
    }
    else ng=(ng+ok)/2;
  }
  int rok=n-ok;
  cout<<max(n-(lok+rok),0)<<endl;
}
