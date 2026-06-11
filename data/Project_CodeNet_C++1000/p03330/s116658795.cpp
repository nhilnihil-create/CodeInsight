#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()

const int inf=2e9;


int main(){
    int n,c; cin>>n>>c;
    vector<vector<int>> d(c,vector<int>(c,0)), pp(n,vector<int>(n,0));
    rep(i,c){
        rep(j,c) cin>>d[i][j];
    }
    rep(i,n){
        rep(j,n) cin>>pp[i][j];
    }
    vector<map<int,int>> p(3);
    rep(i,n){
        rep(j,n){
            p[(i+j)%3][pp[i][j]]++;
        }
    }
    int ans=inf, kari;
    rep(i,c){
        rep(j,c){
            if(i==j) continue;
            rep(k,c){
                if(k==i || k==j) continue;
                kari=0;
                for(auto &v: p[0]){
                    kari+=d[v.first-1][i]*v.second;
                }
                for(auto &v: p[1]){
                    kari+=d[v.first-1][j]*v.second;
                }
                for(auto &v: p[2]){
                    kari+=d[v.first-1][k]*v.second;
                }
                ans=min(ans,kari);
            }
        }
    }
    cout<<ans<<endl;
}