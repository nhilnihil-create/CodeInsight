#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll N;
  cin >> N;
  vl x(N),y(N),h(N);
  rep(i,N){
    cin >> x[i] >> y[i] >> h[i];
  }
  rep(cx,101){
    rep(cy,101){
      bool B=true;
      ll H=0,mxh=1e10;
      rep(i,N){
        ll z;
        if(h[i]==0){
          z=abs(x[i]-cx)+abs(y[i]-cy);
          mxh=min(z,mxh);
        }
        else{
          z=h[i]+abs(x[i]-cx)+abs(y[i]-cy);
          if((H!=0&&H!=z)||mxh<z){
            B=false;
          }
          else{
            H=z;
          }
        }
      }
      if(mxh<H){
        B=false;
      }
      if(B){
        cout << cx << " " << cy << " " << H << endl;
        break;
      }
    }
  }
}