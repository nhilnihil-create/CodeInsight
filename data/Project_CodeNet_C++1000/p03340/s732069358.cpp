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
    vector<ll> ps(n+1), px(n+1);
    ps[0]=p[0]; px[0]=p[0];
    rep(i,n-1){
        ps[i+1]=ps[i]+p[i+1];
        px[i+1]=px[i]^p[i+1];
    }
    ll ans=0;
    rep(i,n){
        if(i==0){
            int ll=0, rr=n,mm;
            while((rr-ll)>1){
                mm=(rr+ll)/2;
                if(ps[mm]!=px[mm]){
                    rr=mm;
                }
                else ll=mm;
            }
            ans+=(ll+1);
            continue;
        }
        int l=i, r=n, m=(l+r)/2;
        while((r-l)>1){
            m=(l+r)/2;
            if((ps[m]-ps[i-1])!=(px[m]^px[i-1])){
                r=m;
            }
            else l=m;
        }
        ll kari=l-i+1;
        //if(kari!=0) cout<<i<<" "<<kari<<endl;
        ans+=kari;
    }
    cout<<ans<<endl;
    return 0;
}