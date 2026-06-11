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
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    ll ans=0, ss=0, xs=0;
    int r=0;
    rep(l,n){
        while(r<n && (ss+p[r])==(xs^p[r])){
            ss+=p[r]; xs^=p[r];
            r++;
        }
        ans+=(r-l);
        if(r==l) r++;
        else{
            ss-=p[l]; xs^=p[l];
        }
    }
    cout<<ans<<endl;
}