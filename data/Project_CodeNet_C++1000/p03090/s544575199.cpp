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
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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

signed main(){
    int N;cin>>N;
    bool G[N+1][N+1];
    REP(i,N+1)REP(j,N+1)G[i][j]=true;
    REP(i,N+1)G[i][i]=false;
    if(N%2==0){
        cout<<(N-2)*N/2<<endl;
        REPS(i,N){
            G[i][N-i+1]=false;
        }
    }
    else{
        cout<<(N-1)*(N-1)/2<<endl;
        REPS(i,N){
            G[i][N-i]=false;
        }
    }
    REPS(i,N)REPS(j,N)if(G[i][j]){
        cout<<i<<" "<<j<<endl;
        G[i][j]=G[j][i]=false;
    }
}