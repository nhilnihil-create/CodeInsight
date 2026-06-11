#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> x(n),y(n),z(n);
    rep(i,n){
        cin>>x[i]>>y[i]>>z[i];
    }

    ll ans=-1LL<<60;
    rep(bit,8){
        vector<ll> tmp(n,0);
        rep(i,n){
            if(bit & 1<<0) tmp[i]+=x[i];
            else tmp[i]-=x[i];
            if(bit & 1<<1) tmp[i]+=y[i];
            else tmp[i]-=y[i];
            if(bit & 1<<2) tmp[i]+=z[i];
            else tmp[i]-=z[i];
        }
        sort(all(tmp));
        reverse(all(tmp));
        ll st=0;
        rep(i,m){
            st+=tmp[i];
        }
        ans=max(ans,st);
    }

    cout<<ans<<endl;
}