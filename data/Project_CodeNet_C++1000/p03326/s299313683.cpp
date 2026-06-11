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
    function<ll(tuple<ll,ll,ll>)> sum=[&](tuple<ll,ll,ll>p){
        ll res=abs(get<0>(p)) + abs(get<1>(p)) + abs(get<2>(p));
        return res;
    };
    int n,m; cin>>n>>m;
    vector<vector<ll>> p(n,vector<ll>(3,0));
    rep(i,n) cin>>p[i][0]>>p[i][1]>>p[i][2];
    ll ans=0;
    rep(i,1<<3){
        vector<int> che(3,0);
        rep(j,3) if(i>>j&1) che[j]=1;
        vector<ll> pp(n,0);
        rep(j,n){
            rep(k,3){
                if(che[k]==0) pp[j]+=p[j][k];
                else pp[j]-=p[j][k];
            }
        }
        sort(etob(pp));
        ll kari=0;
        rep(j,m) kari+=pp[j];
        ans=max(ans,kari);
    }
    cout<<ans<<endl;
    return 0;
}