#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  int n=s.size();
  vector<vector<ll>> dp(n+1,vector<ll>(4,0));
  dp[0][0]=1;
  rep(i,n)rep(j,4){
    if(j==3){
      if(s[i]=='?'){
        (dp[i+1][j]+=(3*dp[i][j])%mod)%=mod;
      }else{
        (dp[i+1][j]+=dp[i][j])%=mod;
      }
    }else if(j==2){
      if(s[i]=='?'){
        (dp[i+1][j+1]+=dp[i][j])%=mod;
        (dp[i+1][j]+=(3*dp[i][j])%mod)%=mod;
      }else if(s[i]=='C'){
        (dp[i+1][j+1]+=dp[i][j])%=mod;
        (dp[i+1][j]+=dp[i][j])%=mod;
      }else{
        (dp[i+1][j]+=dp[i][j])%=mod;
      }
    }else if(j==1){
      if(s[i]=='?'){
        (dp[i+1][j+1]+=dp[i][j])%=mod;
        (dp[i+1][j]+=(3*dp[i][j])%mod)%=mod;
      }else if(s[i]=='B'){
        (dp[i+1][j+1]+=dp[i][j])%=mod;
        (dp[i+1][j]+=dp[i][j])%=mod;
      }else{
        (dp[i+1][j]+=dp[i][j])%=mod;
      }
    }else{
      if(s[i]=='?'){
        (dp[i+1][j+1]+=dp[i][j])%=mod;
        (dp[i+1][j]+=(3*dp[i][j])%mod)%=mod;
      }else if(s[i]=='A'){
        (dp[i+1][j+1]+=dp[i][j])%=mod;
        (dp[i+1][j]+=dp[i][j])%=mod;
      }else{
        (dp[i+1][j]+=dp[i][j])%=mod;
      }
    }
  }
  cout<<dp[n][3]<<endl;
}