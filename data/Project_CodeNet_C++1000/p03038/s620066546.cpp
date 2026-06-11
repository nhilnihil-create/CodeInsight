#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using P  = pair<ll,ll>;

int main(){
    ll n,m;cin>>n>>m;
    v a(n); vector<P> c(m);
    
    rep(i,n)cin >> a[i];
    rep(i,m)cin >> c[i].second >> c[i].first;
    
    sort(a.begin(), a.end());
    sort(c.rbegin(), c.rend());
    
    ll itr = 0;
    v b(n,0);
    
    rep(i,m){
        ll len = min( c[i].second, n-itr );
        for(int j=itr; j<itr+len; j++)
            b[j] = c[i].first;
        itr += len;
        if(itr==n)break;
    }
    
    ll ans = 0;
    rep(i,n)
        ans += max(a[i], b[i]);
    
    cout << ans << endl;
    
    return 0;
}