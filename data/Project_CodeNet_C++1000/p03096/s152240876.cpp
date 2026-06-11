#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int int64_t
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
signed main(){
  int N; cin>>N;
  vi C(N);
  rep(i,0,N) cin>>C[i];
  vi dp(N);
  vi A(200001,-1);
  A[C[0]]=0;
  rep(i,1,N){
    dp[i]=dp[i-1];
    if(A[C[i]]!=-1&&C[i]!=C[i-1]){
        dp[i]=(dp[A[C[i]]]+dp[i])%MOD;
        dp[i]=(dp[i]+1)%MOD;
    }
    A[C[i]]=i;
  }
  cout<<(dp[N-1]+1)%MOD<<endl;
  }

