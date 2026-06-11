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
    int A,B,Q;cin>>A>>B>>Q;
    vector<int>S(A+2);
    vector<int>T(B+2);
    S[0]=-INF;
    S[A+1]=INF;
    T[0]=-INF;
    T[B+1]=INF;
    REPS(i,A)cin>>S[i];
    REPS(i,B)cin>>T[i];
    REP(k,Q){
        int x;cin>>x;
        int ans=INF;
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                auto v=lower_bound(all(S),x);
              	auto w=lower_bound(all(T),x);
              	if(i==1)v--;
              	if(j==1)w--;
                chmin(ans,abs(x-*v)+abs(*w-*v));
            }
        }
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                auto v=lower_bound(all(T),x);
              	auto w=lower_bound(all(S),x);
              	if(i==1)v--;
              	if(j==1)w--;
                chmin(ans,abs(x-*v)+abs(*w-*v));
            }
        }
        cout<<ans<<endl;
    }
}