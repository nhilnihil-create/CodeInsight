#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int q; cin >> q;
    while(q--) {
        ll a, b; cin >> a >> b;
        if(a == b) {
            cout << 2*a - 2 << endl;
            continue;
        }
        auto check = [&] (ll x) {
            return (x + 1) / 2 * (x - (x + 1) / 2 + 1) < a * b;
        };
        ll lb = 1, ub = 1LL << 31;
        while(ub - lb > 1) {
            const ll mid = (lb + ub) / 2;
            (check(mid) ? lb : ub) = mid;
        }
        cout << lb - 1 << endl;
    }
}
