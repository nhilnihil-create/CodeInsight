#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[41][2];

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  string s;
  int i=0;
  while((1ll<<i)<=k){
    if((1ll<<i)&k) s='1'+s;
    else s='0'+s;
    i++;
  }
  int l=s.size();
  rep(i,l)rep(j,2){
    ll x=(1ll<<(l-1-i));
    ll cnt=0;
    rep(m,n){
      if(a[m]&x) cnt++;
    }
    int nj=j;
    if(s[i]=='1'){
      if(i>0) chmax(dp[i+1][nj],dp[i][j]+x*(n-cnt));
      if(i==0) chmax(dp[i+1][0],dp[i][0]+x*(n-cnt));
      chmax(dp[i+1][1],dp[i][j]+x*cnt);
    }
    else{
      chmax(dp[i+1][1],dp[i][1]+x*(n-cnt));
      if(i>0) chmax(dp[i+1][nj],dp[i][j]+x*cnt);
      if(i==0) chmax(dp[i+1][0],dp[i][0]+x*cnt);
    }
  }
  ll ans=0;
  rep(j,2){
    chmax(ans,dp[l][j]);
  }
  for(i=l;i<41;i++){
    ll x=(1ll<<i);
    ll cnt=0;
    rep(m,n){
      if(a[m]&x) cnt++;
    }
    ans+=x*cnt;
  }
  cout << ans << endl;
}
