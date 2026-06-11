#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e17;

int main() {
    ll n, x, ans = 5, bn = INF;
    cin >> n;

    for (int i = 0; i < 5; i++) {
        cin >> x;
        bn = min(bn, x);
    }

    if (bn < n) {
        ans = ans + ((n - 1) / bn);
    }
    cout << ans << endl;
}