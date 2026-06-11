#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k & 1) {
        if (b - a > 1e18) {
            puts("Unfair");
        } else {
            cout << b - a << endl;
        }
    } else {
        if (a - b > 1e18) {
            puts("Unfair");
        } else {
            cout << a - b << endl;
        }
    }
}