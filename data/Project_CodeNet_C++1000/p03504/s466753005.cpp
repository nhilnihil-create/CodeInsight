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
    int n,c; cin>>n>>c;
    vector<int> s(n), t(n), C(n);
    rep(i,n) cin>>s[i]>>t[i]>>C[i];
    vector<vector<int>> p(c+1, vector<int> (1e5+5,0));
    rep(i,n){
        p[C[i]][s[i]]++;
        p[C[i]][t[i]]--;
    }
    vector<int> pp(1e5+5,0);
    rep(i,c+1){
        rep(j,1e5+4){
            if(p[i][j]==1){
                pp[j]++;
            }else if(p[i][j]==-1){
                pp[j+1]--;
            }
        }
    }
    rep(i,1e5+4){
        pp[i+1]+=pp[i];
    }
    int ans=0;
    rep(i,1e5+5){
        chmax(ans, pp[i]);
    }
    cout<<ans<<endl;
    return 0;
}