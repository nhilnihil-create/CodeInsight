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
  int n;cin>>n;
  int a[n];rep(i,n)cin>>a[i];
  ll s[n+1]={};rep(i,n)s[i+1]=s[i]+a[i];
  ll f[n-3];
  f[0]=0;
  int fbar=0;
  rep(i,n-4){
    ll lsum=s[i+3]-s[0];
    while(true){
      ll sumq=s[fbar+1]-s[0];
      ll sumqnext=s[fbar+2]-s[0];
      if(abs((lsum-sumq)-sumq)>abs((lsum-sumqnext)-sumqnext)){
        fbar++;
      }
      else{
        f[i+1]=fbar;break;
      }
    }
  }
  ll g[n-3];
  g[0]=0;
  int gbar=0;
  rep(i,n-4){
    ll rsum=s[n]-s[n-i-3];
    while(true){
      ll sumq=s[n]-s[n-gbar-1];
      ll sumqnext=s[n]-s[n-gbar-2];
      if(abs((rsum-sumq)-sumq)>abs((rsum-sumqnext)-sumqnext)){
        gbar++;continue;
      }
      else{
      g[i+1]=gbar;break;
      }
    }
  }
  ll res=1e18;
  rep(i,n-3){
    ll ans[4];
    ans[0]=s[f[i]+1];
    ans[1]=s[i+2]-ans[0];
    ans[2]=s[n]-s[n-1-g[n-4-i]];
    ans[3]=s[n]-s[i+2]-ans[2];
    sort(ans,ans+4);
    chmin(res,abs(ans[3]-ans[0]));
  }
  cout<<res<<endl;
}
      

