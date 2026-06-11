#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    // x < y < z
    for(int i=0;i<n;i++){
        auto x = upper_bound(a.begin(),a.end(),b[i]-1);
        if(x == a.begin()) continue;
        x--;
        ll lo = x - a.begin();
        auto z = upper_bound(c.begin(),c.end(),b[i]);
        if(z == c.end()) continue;
        ll hi = z - c.begin();
        ll aux = n  - hi;
        ans += (lo+1) * aux;
    }
    cout<<ans<<"\n";
    return 0;
}


