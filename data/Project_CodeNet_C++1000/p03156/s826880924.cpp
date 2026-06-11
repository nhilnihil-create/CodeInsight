#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N,A,B;cin>>N>>A>>B;
    int ac,bc,cc;
    ac=bc=cc=0;
    REP(i,N){
        int a;cin>>a;
        if(a<=A)ac++;
        if(a>A&&a<=B)bc++;
        if(a>B)cc++;
    }
    cout<<min(ac,min(bc,cc))<<endl;
}
