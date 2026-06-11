#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int MAX=3000;

signed main(){
    int N,K;cin>>N>>K;
    int ans=(K!=0?0:-N);
    REPS(b,N){
        ans+=(N/b)*max(0ll,b-K)+max(0ll,N%b-K+1);
    }
    cout<<ans<<endl;
}