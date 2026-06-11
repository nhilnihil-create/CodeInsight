#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
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
int n;
int piyo(int x,int k){
    return (x+k)%n;
}

signed main(){
    cin>>n;
    char s[n][n];
    REP(i,n)REP(j,n)cin>>s[i][j];
    int ans=0;
    REP(k,n){
        bool ok=true;
        REP(i,n)REP(j,n){
            if(s[piyo(i,k)][j]!=s[piyo(j,k)][i]){
                ok=false;
                break;
            }
        }
        if(ok)ans++;
    }
    cout<<ans*n<<endl;
}   