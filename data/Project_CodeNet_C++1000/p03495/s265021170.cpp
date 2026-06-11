#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll n,k; cin >> n >> k;
    ll t=0;
    vector<ll> v(n,0);
    rep(i,n){
        cin >> t;
        v[t-1]++;
    }
    if(k>=n){
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(),v.end());
    ll ans=0;
    rep(i,n-k){
        ans+=v[i];
    }
    cout << ans << endl;
}