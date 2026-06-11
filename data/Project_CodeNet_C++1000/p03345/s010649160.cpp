#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll a, b, c, k; cin >> a >> b >> c >> k;

    if (k % 2 == 0) {
        cout << a - b << endl;
    } else {
        cout << b - a << endl;
    }
}