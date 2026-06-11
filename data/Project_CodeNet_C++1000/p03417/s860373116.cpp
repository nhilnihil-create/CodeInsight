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
    ll ans=0, n,m; cin>>n>>m;
    if(n==1 && m==1){
        cout<<1<<endl;
        return 0;
    }
    ans=(n-2)*(m-2);
    if(n==1){
        ans=max((ll)0,m-2);
    }
    if(m==1){
        ans=max((ll)0,n-2);
    }
    cout<<ans<<endl;
    return 0;
}