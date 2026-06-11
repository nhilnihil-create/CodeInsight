//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
ll flag[1LL<<16];
ll dp[1LL<<16];
ll n;
vvl a(20,vl(20));
ll f(ll S){
  if(flag[S])return dp[S];
  flag[S]=1;
  ll temp=0;
  rep(i,n-1){
    for(ll j=i+1;j<n;j++){
      if(bit(S,i)&&bit(S,j))temp+=a[i][j];
    }
  }
  ll fans=temp;
  for(ll T=(S-1)&S;T>0;T=(T-1)&S){
    fans=max(fans,f(T)+f(S^T));
  }
  dp[S]=fans;
  return fans;
}

int main(){
  cin>>n;
  rep(i,n){
    rep(j,n)cin>>a[i][j];
  }
  cout<<f((1LL<<n)-1)<<endl;
}