#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define at(x,i) get<i>(x);
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll h,w;
void walk(ll &i,ll &j){
  if(j%2==0){
    i++;
    if(i==h){
      i=h-1;
      j++;
    }
  }
  else{
    i--;
    if(i==-1){
      i=0;
      j++;
    }
  }
}
int main(){
  cin >> h >>w;
  vvl f(h,vl(w));
  rep(i,h)rep(j,w){cin >> f[i][j];f[i][j]%=2;}
  ll i=0,j=0;
  ll ans=0;
  vl a,b,c,d;
  while(j<w){
    if(f[i][j]==1){
      while(true){
        a.pb(i+1);b.pb(j+1);
        walk(i,j);
        if(j==w)break;
        c.pb(i+1);d.pb(j+1);
        if(f[i][j]==1)break;
      }
    }
    walk(i,j);
  }
  cout <<d.size() <<endl;
  rep(k,d.size()){
    cout << a[k] <<" " <<b[k] <<" " <<c[k] <<" " <<d[k] <<endl;
  }
}