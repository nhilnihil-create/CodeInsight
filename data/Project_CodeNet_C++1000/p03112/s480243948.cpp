#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a),t(b),x(q);
    rep(i,a) cin>>s[i];
    rep(i,b) cin>>t[i];
    rep(i,q) cin>>x[i];

    sort(all(s));
    sort(all(t));
    rep(i,q){
        if(s[0]>x[i] && t[0]>x[i]) cout<<max(s[0],t[0])-x[i]<<endl;
        else if(s[a-1]<x[i] && t[b-1]<x[i]) cout<<x[i]-min(s[a-1],t[b-1])<<endl;
        else{
            ll ans=1LL<<60;
            int ia=lower_bound(all(s),x[i])-s.begin();
            int ib=lower_bound(all(t),x[i])-t.begin();
            ll sj,tk;
            if(ia!=0 && ib!=b){
                sj=s[ia-1];
                tk=t[ib];
                ans=min(ans,2*min(tk-x[i],x[i]-sj)+max(tk-x[i],x[i]-sj));
                //cout<<sj<<" "<<tk<<endl;
            }
            
            if(ia!=a && ib!=0){
                sj=s[ia];
                tk=t[ib-1];
                ans=min(ans,2*min(x[i]-tk,sj-x[i])+max(x[i]-tk,sj-x[i]));
                //cout<<sj<<" "<<tk<<endl;
            }

            if(ia!=0 && ib!=0){
                sj=s[ia-1];
                tk=t[ib-1];
                ans=min(ans,x[i]-min(tk,sj));
                //cout<<sj<<" "<<tk<<endl;
            }

            if(ia!=a && ib!=b){
                sj=s[ia];
                tk=t[ib];
                ans=min(ans,max(tk,sj)-x[i]);
                //cout<<sj<<" "<<tk<<endl;
            }
            
            cout<<ans<<endl;
        }
    }
}