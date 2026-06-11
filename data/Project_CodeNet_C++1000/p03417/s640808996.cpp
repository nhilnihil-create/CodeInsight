#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int N,M;cin>>N>>M;
    if(N==1&&M==1)cout<<1<<endl;
    else{
      	if(N==1||M==1)cout<<N*M-2<<endl;
    	else cout<<N*M-(2*M+2*N-4)<<endl;
    }
}
