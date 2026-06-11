#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll inf = 1e10;

int main() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    const int p = (x[0] + y[0]) & 1;
    for(int i = 0; i < n; ++i) {
        if(p != ((x[i] + y[i]) & 1)) {
            cout << -1 << endl;
            return 0;
        }
        if(p == 0) {
            y[i] += 1;
        }
    }

    for(int i = 0; i < n; ++i) {
        const int X = x[i] + y[i], Y = x[i] - y[i];
        x[i] = X, y[i] = Y;
    }
    const int m = 31 + (p == 0);
    vector<int> d(m);
    for(int i = 30; i >= 0; --i) {
        d[i] = 1 << i;
    }
    if(p == 0) d[31] = 1;
    vector<string> w(n);
    const string dir = "LDUR";
    for(int i = 0; i < n; ++i) {
        ll cur_x = x[i], cur_y = y[i];
        for(int j = 30; j >= 0; --j) {
            int idx = 0;
            if(abs(cur_x - d[j]) < (1LL << j)) {
                idx |= 0b10;
                cur_x -= d[j];
            } else {
                cur_x += d[j];
            }
            if(abs(cur_y - d[j]) < (1LL << j)) {
                idx |= 0b01;
                cur_y -= d[j];
            } else {
                cur_y += d[j];
            }
            w[i] += dir[idx];
        }
        reverse(begin(w[i]), end(w[i]));
        if(p == 0) {
            w[i] += 'D';
        }
    }

    cout << m << endl;
    for(int i = 0; i < m; ++i) {
        cout << d[i] << " \n"[i + 1 == m];
    }
    for(auto const& s : w) {
        cout << s << endl;
    }
}