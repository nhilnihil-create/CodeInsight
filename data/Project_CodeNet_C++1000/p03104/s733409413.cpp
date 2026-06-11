#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll f(ll a) {
    ll cnt1 = (a+1)/2;
    ll ans = cnt1%2;
    if (a%2 == 0) ans ^= a;
    return ans;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = f(b) ^ f(a-1);
    cout << ans << endl;
    return 0;
}