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
    int a,b,x; cin>>a>>b>>x;
    if(b-a+1<=2*x){
        for(int i=a; i<=b; ++i){
            cout<<i<<endl;
        }
        return 0;
    }
    rep(i,x) cout<<a+i<<endl;
    rep(i,x) cout<<b-x+1+i<<endl;
}