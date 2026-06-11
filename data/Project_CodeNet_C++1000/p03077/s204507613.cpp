#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll mi = min({a, b, c, d, e});
    if(n <= mi) cout << "5" << endl;
    else{
        ll ans = (ll)ceil(n/(double)mi)-1+5;
        cout << ans << endl;
    }
    return 0;
}