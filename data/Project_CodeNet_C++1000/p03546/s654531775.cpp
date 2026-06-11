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
#define chmin(x,y) x=min(x,y)




int main(){
    int h,w; cin>>h>>w;
    vector<vector<int>> c(10, vector<int> (10,0));
    rep(i,10) rep(j,10) cin>>c[i][j];
    vector<vector<int>> p(h,vector<int>(w));
    rep(i,h) rep(j,w) cin>>p[i][j];
    vector<vector<int>> mipath(10, vector<int>(10,0));
    mipath=c;
    rep(kk,10){
      rep(i,10){
        rep(j,10){
          chmin(mipath[i][j], mipath[i][kk]+mipath[kk][j]);
        }
      }
    }
    int ans=0;
    rep(i,h){
      rep(j,w){
        if(p[i][j]==-1) continue;
        if(p[i][j]!=1){
          ans+=mipath[p[i][j]][1];
        }
      }
    }
    cout<<ans<<endl;
    return 0;
}