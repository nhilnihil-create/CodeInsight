#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG

signed main(){
    int N;cin>>N;
    double ans=0;
    REP(i,N){
        double a;string s;cin>>a>>s;
        if(s=="JPY")ans+=a;
        else ans+=a*380000;
    }
  	cout<<setprecision(10.10)<<ans<<endl;
}