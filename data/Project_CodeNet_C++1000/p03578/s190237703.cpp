#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    vector<ll>t(n);
    rep(0,i,n)cin>>t[i];
    ll m;
    cin>>m;
    vector<ll>d(m);
    rep(0,i,m)cin>>d[i];
    sort(t.begin(),t.end());
    sort(d.begin(),d.end());
    ll c=0;
    rep(0,i,n){
        if(c!=m&&t[i]==d[c])++c;
    }
    if(c==m)cout<<"YES";
    else cout<<"NO";
}
