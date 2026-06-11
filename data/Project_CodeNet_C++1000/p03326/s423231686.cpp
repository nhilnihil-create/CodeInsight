#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
    int n,m;
    cin>>n>>m;
    vector<ll> x(n),y(n),z(n);
    rep(i,n) cin>>x[i]>>y[i]>>z[i];

    ll ans=-1LL<<60;
    rep(bit,1<<3){
        vector<ll> v;
        rep(i,n){
            ll tmp=0;
            if(bit & 1<<0) tmp+=x[i];
            else tmp-=x[i];
            if(bit & 1<<1) tmp+=y[i];
            else tmp-=y[i];
            if(bit & 1<<2) tmp+=z[i];
            else tmp-=z[i];
            v.push_back(tmp);
        }
        sort(all(v));
        reverse(all(v));
        ll tmp=0;
        
        rep(i,m) tmp+=v[i];
        //cout<<bit<<" "<<tmp<<endl;
        ans=max(ans,tmp);
    }

    cout<<ans<<endl;
}