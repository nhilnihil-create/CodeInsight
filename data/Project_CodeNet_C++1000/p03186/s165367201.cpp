#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c - 1 <= a + b) {
        cout << b + c;
    } else {
        cout << b + c - (c - a - b - 1);
    }
    cout << endl;

    return 0;
}