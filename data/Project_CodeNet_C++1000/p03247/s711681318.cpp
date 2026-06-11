#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    int parity = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        parity += (abs(x[i]) + abs(y[i])) % 2;
    }

    if (parity != 0 && parity != n) {
        cout << -1 << endl;
        return 0;
    }

    int m = 31 + (parity == 0);
    vector<ll> d(m, 1);

    cout << m << endl;
    cout << d[0];
    for (int i = 1; i < m; i++) {
        d[i] = (1LL << (i % 31));
        cout << " " << d[i];
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        vector<int> ans(m, 0);

        ll u = x[i] + y[i] + (parity == 0);
        u = (u - 1 + (1LL << 31)) >> 1;
        for (int j = 0; j < 31; j++) {
            if (u & (1LL << j)) ans[j] |= 1;
        }

        ll v = x[i] - y[i] + (parity == 0);
        v = (v - 1 + (1LL << 31)) >> 1;
        for (int j = 0; j < 31; j++) {
            if (v & (1LL << j)) ans[j] |= 2;
        }

        for (int j = 0; j < m; j++) {
            cout << "LUDR"[ans[j]];
        }
        cout << endl;
    }
}