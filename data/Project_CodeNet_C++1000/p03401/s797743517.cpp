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
    vector<int>A(N);
    REP(i,N)cin>>A[i];
    vector<pair<int,int>>L(N);
    vector<pair<int,int>>R(N);
    REP(i,N){
        if(i==0)L[0]=mp(0,0);
        else L[i]=mp(L[i-1].first+abs(L[i-1].second-A[i-1]),A[i-1]);
    }
    reverse(A.begin(),A.end());
    REP(i,N){
        if(i==0)R[0]=mp(0,0);
        else R[i]=mp(R[i-1].first+abs(R[i-1].second-A[i-1]),A[i-1]);
    }
    reverse(R.begin(),R.end());
    REP(i,N)cout<<L[i].first+R[i].first+abs(R[i].second-L[i].second)<<endl;
}