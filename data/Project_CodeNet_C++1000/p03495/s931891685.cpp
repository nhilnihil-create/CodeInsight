#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)




int main(){
    int n,k; cin>>n>>k;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    map<int,int> mp;
    rep(i,n){
        mp[p[i]]++;
    }
    vector<int> q;
    for(auto &v: mp){
        q.push_back(v.second);
    }
    sort(btoe(q));
    int spe=q.size();
    int ans=0;
    if(spe<=k){

    }else{
        rep(i,spe-k){
            ans+=q[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}