#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[100][2][2];
int main(){
  ll n,k;
  cin>>n>>k;
  for(int i=0;i<100;i++)for(int j=0;j<2;j++)dp[i][j][1]=-inf;
  V<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=60;i>=0;i--){
    int d=(k&(1ll<<i)?1:0);
    ll cnt=0;
    for(int j=0;j<n;j++)if(a[j]&(1ll<<i))cnt++;
    for(int j=0;j<2;j++){
      for(int l=0;l<2;l++){
      for(int r=0;r<=(j?1:d);r++){
          if(r&&k<(1ll<<i))continue;
          chmax(dp[i][r][(j||r!=d)],dp[i+1][l][j]+(r?n-cnt:cnt)*(1ll<<i));
      }
      }
    }
  }
  cout<<max({dp[0][0][0],dp[0][0][1],dp[0][1][0],dp[0][1][1]})<<"\n";
}
