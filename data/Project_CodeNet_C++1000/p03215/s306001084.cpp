#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int N,K; cin>>N>>K; 
  vi A(N);
  rep(i,0,N) cin>>A[i];
  vi dp(N+1);
  rep(i,0,N) dp[i+1]=dp[i]+A[i];
  vi B;
  REP(i,1,N){
    rep(j,0,i) B.pb(dp[i]-dp[j]);
  }
  int ans=0;
  REP(i,0,60){
    int k=60-i;
    int count=0;
    rep(j,0,B.size()){
      if((B[j]|(ans+(1ll<<k)))==B[j]) count++;
    }
    if(K<=count) ans+=(1ll<<k);
  }
  cout<<ans<<endl;
  }

