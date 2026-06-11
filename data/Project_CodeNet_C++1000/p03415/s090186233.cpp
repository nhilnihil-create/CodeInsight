#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    char A[3][3];
    REP(i,3){
        REP(j,3)cin>>A[i][j];
    }
    cout<<A[0][0]<<A[1][1]<<A[2][2]<<endl;
}
