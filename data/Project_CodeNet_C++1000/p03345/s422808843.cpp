#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = k; i < (n); i++)
using ll = long long;
const ll K = 1000000000000000000;

int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans;
    if (k%2 == 0) ans = a - b;
    else ans = b - a;
    if (abs(b - a) >= K) cout << "Unfair" << endl;
    else cout << ans << endl;
    return 0;
}