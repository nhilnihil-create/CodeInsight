#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a,b,q;cin>>a>>b>>q;
    ll s[a+2],t[b+2];
    s[0]=t[0]=-1e18;
    s[a+1]=t[b+1]=1e18;
    for (int i=1;i<=a;i++)
        cin>>s[i];
    for (int i=1;i<=b;i++)
        cin>>t[i];
    for (int i=0;i<q;i++) {
        ll x;cin>>x;
        auto it=lower_bound(s,s+a+2,x);
        ll c=*it-x;
        ll d=x-*(it-1);
        it=lower_bound(t,t+b+2,x);
        ll e=*it-x;
        ll f=x-*(it-1);
        ll mn=min(max(c,e),min(c,f)+c+f);
        mn=min(mn,min(d,e)+d+e);
        mn=min(mn,max(d,f));
        cout<<mn<<endl;
    }
    return 0;
}