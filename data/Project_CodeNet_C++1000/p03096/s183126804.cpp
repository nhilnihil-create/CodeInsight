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
  int n;
  cin>>n;
  vector<int> c(n+1,0);
  rep(i,n) cin>>c[i+1];
  map<int,int> cnt;
  vector<int> dp(n+1,0);
  dp[0]=1;
  FOR(i,1,n+1){
    if(c[i-1]==c[i]){
      (dp[i]+=dp[i-1])%=mod;
    }else{
      (dp[i]+=dp[i-1]+cnt[c[i]])%=mod;
    }
    cnt[c[i]]=dp[i];
  }
  //cout_vec(dp);
  cout<<dp[n]<<endl;
}