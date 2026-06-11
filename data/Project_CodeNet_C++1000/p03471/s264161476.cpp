#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,y; cin>>n>>y;
    int a=0, b=0, c=0;
    bool ok=false;
    rep(i,n+1){
        if(i*10000>y) break;
        int now=y-i*10000;

        int cntb=now-1000*(n-i), cntc=5000*(n-i)-now;
        if(cntb%4000==0 && cntc%4000==0 && cntb>=0 && cntc>=0){
            ok=true;
            a=i;
            b=cntb/4000;
            c=cntc/4000;
        }
        if(ok) break;
    }
    if(ok){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }else{
        rep(i,3){
            cout<<-1<<" ";
        }
    }
}