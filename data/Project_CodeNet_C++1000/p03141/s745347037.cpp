#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> apb(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ans -= b; 
        apb[i] = a + b;
    }
    sort(apb.begin(), apb.end());
    reverse(apb.begin(), apb.end());
    rep(i, n) {
        if ( i & 1 ) continue;
        else         ans += apb[i]; 
    }
    cout << ans << endl;
    return 0;
}
