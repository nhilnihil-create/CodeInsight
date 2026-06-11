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
    vector<int> p(3);
    rep(i,3) cin>>p[i];
    int k; cin>>k;
    sort(etob(p));
    rep(i,k) p[0]*=2;
    int ans=0;
    rep(i,3) ans+=p[i];
    cout<<ans<<endl;
    return 0;
}