#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,H,W;
    cin >> n >> H >> W;
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        if(a>=H&&b>=W)ans++;
    }
    cout << ans << endl;
}
