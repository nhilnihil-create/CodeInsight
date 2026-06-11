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

const int inf=2e9+5;


int main(){
    int n; cin>>n;
    vector<vector<int>> f(n, vector<int>(10,0));
    rep(i,n){
        rep(j,10){
            cin>>f[i][j];
        }
    }
    vector<vector<int>> p(n, vector<int>(11,0));
    rep(i,n) rep(j,11) cin>>p[i][j];
    int ans=-inf;
    for(int i=1; i<1<<10; ++i){
        int karians=0;
        rep(j,n){
            int kari=0;
            rep(kk,10){
                if(f[j][kk]==1 && i>>kk&1){
                    kari++;
                }
            }
            karians+=p[j][kari];
        }
        ans=max(ans, karians);
    }
    cout<<ans<<endl;
    return 0;
}