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
  int N,M; cin>>N>>M;
  vi A(M),P={2,5,5,4,5,6,3,7,6};
  rep(i,0,M) cin>>A[i];
  vector<string> dp(N+1,"-1");
  dp[0]="";
  REP(i,1,N){
    rep(j,0,M){
      int X=P[A[j]-1];
      if(i-X>=0&&dp[i-X]!="-1"){
        string S=dp[i-X];
        S+='0'+A[j];
        sort(ALL(S),greater<char>());
        if(dp[i]=="-1") dp[i]=S;
        else if(S.size()>dp[i].size()) dp[i]=S;
        else if(S.size()==dp[i].size()&&S>dp[i]) dp[i]=S;
      }
    }
  }
  cout<<dp[N]<<endl;
  }
