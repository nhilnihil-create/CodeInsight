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
    int a,b,c,x; cin>>a>>b>>c>>x;
    int ans=0;
    rep(i,a+1){
        rep(j,b+1){
            rep(K,c+1){
                if(x==i*500+j*100+K*50) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}