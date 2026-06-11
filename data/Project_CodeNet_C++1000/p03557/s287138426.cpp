#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n),b(n),c(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    for(ll i=0;i<n;i++) cin >> b[i];
    for(ll i=0;i<n;i++) cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans=0;
    vector<ll>bc(n+1,0);
    for(ll i=0;i<n;i++){
        auto ite=upper_bound(c.begin(),c.end(),b[i]);
        bc[i+1]=c.end()-ite;
    }
    for(ll i=1;i<n+1;i++){
        bc[i]+=bc[i-1];
    }
    for(ll i=0;i<n;i++){
        auto ite1=upper_bound(b.begin(),b.end(),a[i]);
        ll x=ite1-b.begin();
        ans+=bc[n]-bc[x];
    }
    cout << ans << endl;
}