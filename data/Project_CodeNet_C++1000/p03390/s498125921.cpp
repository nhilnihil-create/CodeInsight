#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int q; cin >> q;
    while(q--) {
        ll a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        if(a == b || a + 1 == b) {
            cout << 2 * a - 2 << endl;
        } else {
            ll c = sqrt(a * b);
            if(c * c == a * b) c--;
            if(c * (c + 1) >= a * b) {
                cout << 2 * c - 2 << endl;
            } else {
                cout << 2 * c - 1 << endl;
            }
        }
    }
}
