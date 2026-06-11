#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ma = max({a, b, c});

    if ((3 * ma - a - b - c) % 2 == 0)
        cout << (3 * ma - a - b - c) / 2;
    else
        cout << (3 * (ma + 1) - a - b - c) / 2;
    cout << endl;

    return 0;
}