#include<bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

ll N;
ll dp[20010];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>N;
  vector<tuple<ll,ll,ll> > blocks(N);
  for(ll i=0;i<N;i++){
    ll w,s,v;cin>>w>>s>>v;
    blocks[i]=make_tuple(s+w,s,v);
  }
  sort(blocks.begin(),blocks.end());
  for(ll i=0;i<N;i++){
    ll w,s,v;tie(w,s,v)=blocks[i];
    w -= s;
    for(ll j=s;j>=0;j--){
      dp[j+w]=max(dp[j+w],dp[j]+v);
    }
  }
  ll ans = 0;
  for(ll j=0;j<=20010;j++){
    ans = max(ans,dp[j]);
  }
  cout<<ans<<endl;
  return 0;
}
