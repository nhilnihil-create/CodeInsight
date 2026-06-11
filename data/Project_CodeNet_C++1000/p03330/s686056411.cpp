#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9+7;
int main(){
  ll n,c;
  cin>>n>>c;
  vvll iwakan(c,vll(c)),color(n,vll(n));
  vll c0(c,0),c1(c,0),c2(c,0);
  rep(i,0,c){rep(j,0,c)cin>>iwakan[i][j];} 
  rep(i,0,n){rep(j,0,n){cin>>color[i][j];color[i][j]--;} }
  rep(i,0,n){
    rep(j,0,n){
      if((i+j)%3==0){c0[color[i][j]]++;}
      if((i+j)%3==1){c1[color[i][j]]++;}
      if((i+j)%3==2){c2[color[i][j]]++;}
    }
  }
  ll sum=INF;
  rep(i,0,c){//mod3=0
    rep(j,0,c){//mod3=1
      if(j!=i){
        rep(k,0,c){//mod3=2
          if(k!=i&&k!=j){
            ll tmp=0;
            rep(h,0,c){
              tmp+=iwakan[h][i]*c0[h];
              tmp+=iwakan[h][j]*c1[h];
              tmp+=iwakan[h][k]*c2[h];
            }
            sum=min(sum,tmp);
          }
        }
      }
    }
  }
  cout<<sum<<endl;
}
