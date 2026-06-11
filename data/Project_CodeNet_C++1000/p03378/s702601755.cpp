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
    int n,m,x; cin>>n>>m>>x;
    vector<int> p(n,0);
    rep(i,m){
        int a; cin>>a;
        p[a]++;
    }
    int an=0, ans=0;
    rep(i,x){
        if(p[i]==1) an++;
    }
    for(int i=x+1; i<n; ++i){
        if(p[i]==1) ans++;
    }
    ans=min(ans,an);
    cout<<ans<<endl;
    return 0;
}