#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<string> p(n);
    map<string,int> mp;
    rep(i,n){
        cin>>p[i];
        mp[p[i]]++;
    }
    bool ok=true;
    for(auto& v: mp){
        if(v.second>1) ok=false;
    }
    rep(i,n-1){
        if(p[i+1][0]!=p[i][p[i].size()-1]) ok=false;
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}