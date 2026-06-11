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
  int N,Q; string S; cin>>N>>S>>Q;
  vi M(N+1),C(N+1),dp(N+1);
  rep(i,0,N){
    M[i+1]=M[i];
    if(S[i]=='M') M[i+1]++;
  }
  rep(i,0,N){
    C[i+1]=C[i];
    dp[i+1]=dp[i];
    if(S[i]=='C'){
      dp[i+1]+=M[i+1];
      C[i+1]++;
    }
  }
  rep(_,0,Q){
    int ans=0;
    int X; cin>>X;
    rep(i,0,N){
      if(S[i]=='D'){
        ans+=dp[min(N,i+X)]-dp[i+1]-M[i+1]*(C[min(N,i+X)]-C[i+1]);
      }
    }
    cout<<ans<<endl;
  }
  }

