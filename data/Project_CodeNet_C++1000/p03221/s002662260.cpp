#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll  = long long;
using v   = vector<int>;
using P   = pair<int,int>;
using vp  = vector<P>;
using vvp = vector<vp>;

int main(){
    int n,m; cin>>n>>m;
    
    vvp pyi(n);
    
    int p,y;
    rep(i,m){
        cin>>p>>y;
        p--;
        pyi[p].emplace_back(y,i);
    }
    
    rep(i,n){
        sort(pyi[i].begin(), pyi[i].end());
    }
    
    vp num(m);
    
    rep(i,n){
        rep(j,pyi[i].size()){
            num[pyi[i][j].second].first = i+1;
            num[pyi[i][j].second].second = j+1;
        }
    }
    
    rep(i,m){
        printf("%06d%06d\n", num[i].first, num[i].second);
    }
    
    return 0;
}