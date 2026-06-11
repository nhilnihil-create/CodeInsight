#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int K;
  cin>>K;
  vector<int>A(K);
  for(int i=0;i<K;i++)cin>>A[i];
  ll r=pow(10,15);
  ll l=-1;
  ll m;
  while(r-l>1){
    m=(r+l)/2;
    vector<ll>dp(K+1);
    dp[0]=m;
    for(int i=1;i<=K;i++)dp[i]=(dp[i-1]/A[i-1])*A[i-1];
    if(dp[K]<2)l=m;
    else r=m;
  }
  ll down=r;
  r=pow(10,15);
  l=-1;
  m;
  while(r-l>1){
    m=(r+l)/2;
    vector<ll>dp(K+1);
    dp[0]=m;
    for(int i=1;i<=K;i++)dp[i]=(dp[i-1]/A[i-1])*A[i-1];
    if(dp[K]<=2)l=m;
    else r=m;
  }
  ll up=l;

  bool ok=true;
  vector<ll>dp(K+1);
  dp[0]=down;
  for(int i=1;i<=K;i++)dp[i]=(dp[i-1]/A[i-1])*A[i-1];
  if(dp[K]!=2)ok=false;
  dp[0]=up;
  for(int i=1;i<=K;i++)dp[i]=(dp[i-1]/A[i-1])*A[i-1];
  if(dp[K]!=2)ok=false;

  if(ok)cout<<down<<" "<<up<<endl;
  else cout<<-1<<endl;
  return 0;
}

