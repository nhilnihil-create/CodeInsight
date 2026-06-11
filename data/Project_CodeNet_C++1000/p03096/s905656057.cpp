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
const int MAX=2e5+1;

signed main(){
    int N;cin>>N;
    int C[N];
    vector<int> Cp[MAX];
  	REP(i,MAX)Cp[i].clear();
    REP(i,N){
        cin>>C[i];
        Cp[C[i]].pb(i);
    }
    int dp[N+1];
  	REPS(i,N)dp[i]=0;
    dp[0]=1;
    REPS(i,N){
        dp[i]+=dp[i-1];
        int c=C[i-1];
        int itr=lower_bound(all(Cp[c]),i-1)-Cp[c].begin();
        if(itr>0){
            int d=Cp[c][itr-1];
            if(i-d>2)dp[i]+=dp[d+1];
        }
        dp[i]%=MOD;
    }
    cout<<dp[N]<<endl;
}
