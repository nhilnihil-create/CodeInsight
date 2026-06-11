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
    int n; cin>>n;
    string s; cin>>s;
    int ans=0;
    string t,u;
    rep(i,n-1){
        t=s.substr(0,i+1);
        u=s.substr(i+1,n-i-1);
        map<char,int> mp, mpp;
        int kari=0;
        for(auto& v: t) mp[v]++;
        for(auto& v: u) mpp[v]++;
        for(auto &v: mp){
            for(auto &w: mpp){
                if(v.first==w.first) kari++;
            }
        }
        ans=max(ans,kari);
    }
    cout<<ans<<endl;
    return 0;
}