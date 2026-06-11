#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    vector<int>A(3);
    REP(i,3)cin>>A[i];
    sort(A.rbegin(),A.rend());
    cout<<A[0]*10+A[1]+A[2]<<endl;
}