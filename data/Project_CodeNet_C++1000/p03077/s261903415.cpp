#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll minnum = 2000000000000000;
    vector<ll> t(5);
    rep(i, t.size()) {
        cin >> t[i];
        minnum = min(minnum, t[i]);
    }

    ll g = n / minnum;
    if (n % minnum != 0) g++;
    ll ans = 5 + (g - 1);
    cout << ans << endl;
}