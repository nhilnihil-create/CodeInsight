//#define _GLIBCXX_DEBUG
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
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll X,Y,Z,K;
  cin >> X >> Y >> Z >> K;
  vl A(X),B(Y),C(Z);
  rep(i,X){
    cin >> A[i];
  }
  rep(i,Y){
    cin >> B[i];
  }
  rep(i,Z){
    cin >> C[i];
  }
  vl D(X*Y);
  rep(i,X){
    rep(j,Y){
      D[i+X*j]=A[i]+B[j];
    }
  }
  sort(D.begin(),D.end());
  sort(C.begin(),C.end());
  reverse(D.begin(),D.end());
  reverse(C.begin(),C.end());
  vl ND(min(K,X*Y));
  rep(i,(ll)ND.size()){
    ND[i]=D[i];
  }
  vl E((ll)ND.size()*Z);
  rep(i,(ll)ND.size()){
    rep(j,Z){
      E[i+ND.size()*j]=ND[i]+C[j];
    }
  }
  sort(E.begin(),E.end());
  reverse(E.begin(),E.end());
  rep(i,K){
    cout << E[i] << endl;
  }
}