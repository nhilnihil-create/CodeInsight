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
    int H,W;cin>>H>>W;
    int d[10][10];
    REP(i,10)REP(j,10)cin>>d[i][j];
    REP(k,10)REP(i,10)REP(j,10)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    map<int,int>memo;
    REP(i,H*W){
        int a;cin>>a;
        if(a!=-1)memo[a]++;
    }
    int ans=0;
    for(auto v:memo){
        ans+=v.second*d[v.first][1];
    }
    cout<<ans<<endl;
}