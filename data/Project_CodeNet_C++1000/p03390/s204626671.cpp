#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll rt = sqrt((long double)(a * b));
        rt = max(1LL, rt - 2);
        ll z = a * b - 1;
        while (z / rt != z / (rt + 1)) {
            ++rt;
        }
        int kek = 1;
        if (a == b) {
            --kek;
        }
        cout << z / rt - 1 + rt - kek << '\n';
    }
    return 0;
}