#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define zero_pad(num) setfill('0') << std::right << setw(num)
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int N,M;cin>>N>>M;
    vector<int>P(M),Y(M);
    vector<int>PY[N+1];
    REP(i,M){
        cin>>P[i]>>Y[i];
        PY[P[i]].pb(Y[i]);
    }
    map<int,int>memo;
    REPS(i,N){
        sort(PY[i].begin(),PY[i].end());
        REP(j,PY[i].size()){
            memo[PY[i][j]]=j+1;
        }
    }
    REP(i,M)cout<<zero_pad(6)<<P[i]<<zero_pad(6)<<memo[Y[i]]<<endl;
}