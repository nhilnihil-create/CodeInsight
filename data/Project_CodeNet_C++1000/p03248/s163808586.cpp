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

signed main(){
    string S;cin>>S;
    int N=S.size();
    vector<int>piyo;
    if(S[0]=='0'||S[N-1]=='1'){
        cout<<-1<<endl;
        return 0;
    }
    REP(i,N){
        if(S[i]=='1')piyo.pb(i);
    }
  	S[N-1]='1';
    REP(i,N/2){
        if(S[i]!=S[N-2-i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    piyo.pb(N-1);
    REP(i,N-1){
        auto v=upper_bound(piyo.begin(),piyo.end(),i);
        cout<<i+1<<" "<<1+*v<<endl;
    }
}