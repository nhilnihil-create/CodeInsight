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
  string s;cin>>s;
  ll d[n+1],dm[n+1],m[n+1];
  d[0]=dm[0]=m[0]=0;
  rep(i,n){
    d[i+1]=d[i];
    m[i+1]=m[i];
    dm[i+1]=dm[i];
    if(s[i]=='D')d[i+1]++;
    if(s[i]=='M'){
      m[i+1]++;
      dm[i+1]+=d[i];
    }
  }
  int q;cin>>q;
  rep(i,q){
    int k;cin>>k;
    ll ans=0;
    rep(j,n){
      if(s[j]!='C')continue;
      ans+=dm[j]-dm[max(0,j-k+1)];
      ans-=d[max(0,j-k+1)]*(m[j]-m[max(0,j-k+1)]);
    }
    cout<<ans<<endl;
  }
}