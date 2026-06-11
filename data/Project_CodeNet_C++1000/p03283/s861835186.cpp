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

signed main(){
    int N,M,Q;cin>>N>>M>>Q;
    int Table[N+1][N+1];
    REP(i,N+1)REP(j,N+1)Table[i][j]=0;
    REP(i,M){
        int l,r;cin>>l>>r;
        Table[l][r]++;
    }
    int sumT[N+1][N+1];
  	REP(i,N+1)REP(j,N+1)sumT[i][j]=0;
    REPS(i,N){
        REPS(j,N){
            if(j==1)sumT[i][1]=Table[i][1];
            else sumT[i][j]=sumT[i][j-1]+Table[i][j];
        }
    }
    REP(i,Q){
        int l,r;cin>>l>>r;
        int ans=0;
        for(int z=l;z<=r;z++){
            ans+=sumT[z][r]-sumT[z][l-1];
        }
        cout<<ans<<endl;
    }
}