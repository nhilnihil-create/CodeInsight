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
    map<int,int> mp;
    rep(i,n){
        int a; cin>>a;
        mp[a]++;
    }
    int ans=0;
    for(auto &v: mp){
        if(v.first<v.second){
            ans+=v.second-v.first;
        }else if(v.first>v.second){
            ans+=v.second;
        }
    }
    cout<<ans<<endl;
    return 0;
}