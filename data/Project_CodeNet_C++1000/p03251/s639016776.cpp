#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;
 
signed main(){
    int N,M,X,Y;cin>>N>>M>>X>>Y;
    int xm=-100;
    REP(i,N){
        int a;cin>>a;
        xm=max(xm,a);
    }
  	int ym=INF;
    REP(i,M){
        int b;cin>>b;
        ym=min(b,ym);
    }
  	bool ok=false;
    if(xm<ym){
        for(int i=xm+1;i<=ym;i++){
            if(i>X&&i<=Y)ok=true;
            break;
        }
    }
    if(ok)cout<<"No War"<<endl;
    else cout<<"War"<<endl;
}