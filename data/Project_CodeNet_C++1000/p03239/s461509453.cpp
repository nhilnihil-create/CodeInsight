#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N,T;cin>>N>>T;
    bool ok=false;
    int ans=INF;
    REP(i,N){
        int a,b;cin>>a>>b;
        if(b<=T){
            ans=min(ans,a);
            ok=true;
        }
    }
    if(ok) cout<<ans<<endl;
    else cout<<"TLE"<<endl;
}
