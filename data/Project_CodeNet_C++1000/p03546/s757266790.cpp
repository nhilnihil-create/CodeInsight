#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

bool isprime(int x){
    int y=x;
    for(int i=2;i<=sqrt(x);i++){
        while(y%i==0)y/=i;
    }
    if(y==x)return true;
    return false;
}

signed main(){
    int H,W;cin>>H>>W;
    int d[10][10];
    REP(i,10)REP(j,10)cin>>d[i][j];
    REP(k,10)REP(i,10)REP(j,10)chmin(d[i][j],d[i][k]+d[k][j]);
    int ans=0;
    REP(i,H*W){
        int a;cin>>a;
        if(a!=-1)ans+=d[a][1];
    }
    cout<<ans<<endl;
}