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

signed main(){
    int X,Y,Z,K;cin>>X>>Y>>Z>>K;
    vector<int>A(X),B(Y),C(Z);
    REP(i,X)cin>>A[i];
    REP(i,Y)cin>>B[i];
    REP(i,Z)cin>>C[i];
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    sort(C.rbegin(),C.rend());
    vector<int>ans;
    REP(i,X){
        REP(j,Y){
            REP(k,Z){
                if((i+1)*(j+1)*(k+1)>K)break;
                else ans.eb(A[i]+B[j]+C[k]);
            }
        }
    }
    sort(ans.rbegin(),ans.rend());
    REP(i,K)cout<<ans[i]<<endl;
}