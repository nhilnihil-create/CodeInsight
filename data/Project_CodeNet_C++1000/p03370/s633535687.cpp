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
    int n,x; cin>>n>>x;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    rep(i,n){
        x-=p[i];
    }
    sort(btoe(p));
    int ans=n;
    if(x!=0){
        ans+=(x/p[0]);
    }
    cout<<ans<<endl;
    return 0;
}