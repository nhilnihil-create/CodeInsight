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

int powMOD(int n,int r){
    if(r==0)return 1;
    if(r%2==0)return powMOD(n,r/2)*powMOD(n,r/2)%MOD;
    if(r%2==1)return powMOD(n,r-1)*n%MOD;
}

int modFAC(int x){
    if(x==1) return 1;
    return x*modFAC(x-1)%MOD;
}

int COM(int n,int r){
    int ret=1;
    REP(i,r){
        ret *= (n-i);
        ret %=MOD;
    }
    return ret*powMOD(modFAC(r),1e9+5)%MOD;
}

signed main(){
    int n;cin>>n;
    int ans=0;
    REP(i,n){
        int a;cin>>a;
        while(a%2==0){
            ans++;
            a/=2;
        }
    }
    cout<<ans<<endl;
}