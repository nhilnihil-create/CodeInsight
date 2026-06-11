#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<ll> p,c;

//dp
vector<vector<ll>> table;

ll alpha(ll i,ll k){
  if(k==p[i]) return c[i];
  else return 0;
}

ll dp(ll i,ll j){
  if(i<=0||j<=0) return 0;
  if(table[i][j]>-INF) return table[i][j];
  
  ll ret=-INF+1;
  rep(k,p[i]+1){
    if(j-k<0) break;
    chmax(ret,dp(i-1,j-k)+i*k+alpha(i,k));
  }
  
  return table[i][j]=ret;
}

int main()
{
  ll D,G; cin>>D>>G; G/=100;
  ll P=0;
  p=vector<ll>(D+1),c=vector<ll>(D+1); rep(i,D) {cin>>p[i+1]>>c[i+1]; P+=p[i+1],c[i+1]/=100;}
  
  //dp
  table=vector<vector<ll>>(D+1,vector<ll>(P+1,-INF));
  /*
  rep(i,D+1){
    rep(j,P+1){
      if(j!=0) cout<<" ";
      cout<<dp(i,j);
    }
    cout<<endl;
  }
  */
  rep(i,P+1){
    if(dp(D,i)>=G){cout<<i<<endl; return 0;}
  }
  
  
  
  return 0;
}
