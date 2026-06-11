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
    int N;cin>>N;
    vector<int>A(N),B(N),C(N);
    REP(i,N)cin>>A[i];
    REP(i,N)cin>>B[i];
    REP(i,N)cin>>C[i];
    sort(A.begin(),A.end());
    sort(C.begin(),C.end());
    int ans=0;
    REP(i,N){
        int b=B[i];
        auto d=lower_bound(A.begin(),A.end(),b);
        auto e=upper_bound(C.begin(),C.end(),b);
        ans+=(d-A.begin())*(C.end()-e);
    }
    cout<<ans<<endl;
}
