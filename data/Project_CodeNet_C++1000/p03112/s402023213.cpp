#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a), t(b), x(q);
    rep(i,a) cin>>s[i];
    rep(i,b) cin>>t[i];
    rep(i,q) cin>>x[i];
    sort(btoe(s)); sort(btoe(t));
    rep(i,q){
        int l1=0, l2=0, r1=a-1, r2=b-1;
        int m1,m2;
        ll ans;
        while(r1-l1>1){
            m1=(l1+r1)/2;
            if(s[m1]>x[i]) r1=m1;
            else l1=m1;
        }
        while(r2-l2>1){
            m2=(l2+r2)/2;
            if((t[m2]>x[i])) r2=m2;
            else l2=m2;
        }
        ll ans1=abs(x[i]-s[l1])+min(abs(s[l1]-t[l2]),abs(s[l1]-t[r2]));
        ll ans2=abs(x[i]-s[r1])+min(abs(s[r1]-t[l2]),abs(s[r1]-t[r2]));
        ll ans3=abs(x[i]-t[l2])+min(abs(t[l2]-s[l1]),abs(t[l2]-s[r1]));
        ll ans4=abs(x[i]-t[r2])+min(abs(t[r2]-s[l1]),abs(t[r2]-s[r1]));
        ans=ans1;
        ans=min(ans,ans2);
        ans=min(ans,ans3);
        ans=min(ans,ans4);
        cout<<ans<<endl;
    }
    return 0;
}