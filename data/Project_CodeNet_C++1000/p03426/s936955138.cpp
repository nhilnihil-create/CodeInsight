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
    int h,w,d; cin>>h>>w>>d;
    vector<P> p(h*w);
    rep(i,h){
        rep(j,w){
            int a; cin>>a;
            a--;
            p[a]={i,j};
        }
    }
    vector<int> cost(h*w,0);
    rep(i,d){
        for(int j=i; j<h*w-d; j+=d){
            cost[j+d]=cost[j]+abs(p[j+d].first-p[j].first)+abs(p[j+d].second-p[j].second);
        }
    }
    int qqq; cin>>qqq;
    rep(qqqq,qqq){
        int r,l; cin>>l>>r;
        l--; r--;
        ll ans=0;
        ans=cost[r]-cost[l];
        cout<<ans<<endl;
    }
    return 0;
}