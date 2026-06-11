#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ll a, b, k;
    cin >> a >> b >> k;

    for (int i = 0; i < k; ++i) {
        if (i % 2 == 0) { // A
            if (a % 2) --a;
            b += a / 2;
            a /= 2;
        }
        else { // B
            if (b % 2) --b;
            a += b / 2;
            b /= 2;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
