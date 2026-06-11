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
    int n,d,x; cin>>n>>d>>x;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    int ans=x;
    rep(i,n){
        int kari=(d-1)/p[i];
        ans+=(kari+1);
    }
    cout<<ans<<endl;
}