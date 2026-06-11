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
const int MAX_N=1e5;

signed main(){
    int N;cin>>N;
    int dp[N+1];
    vector<int> cp[200000];
    REP(i,200000)cp[i].clear();
    vector<int>C(N);
    REP(i,N){
        int a;cin>>a;a--;
        C[i]=a;
        cp[a].pb(i);
    }
    dp[0]=1;
    REP(i,N){
        dp[i+1]=dp[i]%MOD;
        int color=C[i];
        int it=lower_bound(all(cp[color]),i)-cp[color].begin();
        if(it!=0){
            int d=cp[color][it-1];
            if(i-d>1)dp[i+1]+=dp[d+1];
        }
      	dp[i+1]%=MOD;
    }
    cout<<dp[N]<<endl;
}