#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

struct P {
    int x, y;
};

int main() {
    int n;
    cin >> n;

    vector<P> p(n);
    int b = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if ((x + y) % 2 == 0) b++;
        p[i] = { x, y };
    }

    if (b % n) {
        cout << -1 << endl;
        exit(0);
    }
    b /= n;

    int l = 31;
    int m = l + b;
    vector<int> d(m, 1);
    int s = -b;
    for (int j = 0; j < l; j++) {
        s += d[j] = 1 << j;
    }

    cout << m << '\n';
    for (int j = 0; j < m; j++) {
        cout << d[j] << " \n"[j == m - 1];
    }

    const char *c = "LDUR";
    string r(m, 'R');
    for (int i = 0; i < n; i++) {
        uint32_t x = p[i].x - p[i].y + s;
        uint32_t y = p[i].x + p[i].y + s;

        for (int j = 0; j < l; j++) {
            x >>= 1;
            y >>= 1;
            r[j] = c[(x & 1) + (y & 1) * 2];
        }
        cout << r << '\n';
    }

    return 0;
}