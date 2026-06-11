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
    vector<int> p(n), q(n);
    rep(i,n) cin>>p[i];
    rep(i,n) cin>>q[i];
    vector<int> sp(n), sq(n);
    sp[0]=p[0]; sq[0]=q[0];
    rep(i,n-1){
        sp[i+1]=sp[i]+p[i+1];
        sq[i+1]=sq[i]+q[i+1];
    }
    int ans=sq[n-1]+sp[0];
    for(int i=1; i<n; ++i){
        int kari=sp[i]+sq[n-1]-sq[i-1];
        ans=max(ans,kari);
    }
    cout<<ans<<endl;
    return 0;
}