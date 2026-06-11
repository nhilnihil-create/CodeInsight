#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

int powMOD(int x,int r){
    if(r==0)return 1;
    if(r&2==0)return powMOD(x,r/2)+powMOD(x,r/2)%MOD;
    return x*powMOD(x,r-1)%MOD;
}

signed main(){
    string S;cin>>S;
    int N=S.size();
    int dp[100010][4];
    REP(i,100010)REP(j,4)dp[i][j]=0;
  	dp[0][0]=1;
    REP(i,N){
        if(S[i]=='?'){
            REP(j,4)dp[i+1][j]+=dp[i][j]*3;
            REP(j,3)dp[i+1][j+1]+=dp[i][j];
        }
        if(S[i]=='A'){
            REP(j,4)dp[i+1][j]+=dp[i][j];
            dp[i+1][1]+=dp[i][0];
        }
        if(S[i]=='B'){
            REP(j,4)dp[i+1][j]+=dp[i][j];
            dp[i+1][2]+=dp[i][1];
        }
        if(S[i]=='C'){
            REP(j,4)dp[i+1][j]+=dp[i][j];
            dp[i+1][3]+=dp[i][2];
        }
        REP(j,4)dp[i+1][j]%=MOD;
    }
    cout<<dp[N][3]<<endl;
}