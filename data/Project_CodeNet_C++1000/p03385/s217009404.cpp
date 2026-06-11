#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    string S;cin>>S;
    bool ok=false;
    bool ok1=false;
    bool ok2=false;
    REP(i,3){
        if(S[i]=='a')ok=true;
        if(S[i]=='b')ok1=true;
        if(S[i]=='c')ok2=true;
    }
    if(ok&&ok1&&ok2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
