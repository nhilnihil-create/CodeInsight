#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int main() {
    ull n, x[1000], y[1000], c[2];
    cin >> n;
    for (ull i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        c[(x[i] + y[i]) % 2]++;
    }
    if (c[0] && c[1]) {
        cout << -1 << endl;
        return 0;
    }
    cout << (c[0] ? 33 : 32) << endl;
    if (c[0]) cout << "1 ";
    ull s = 0;
    for (ull i = 0; i < 32; i++) {
        cout << ((ull)1 << i) << ' ';
        s |= ((ull)1 << i);
    }
    cout << endl;
    char t[2][2] = {
            {'L', 'D'},
            {'U', 'R'}
    };
    for (ull i = 0; i < n; i++) {
        if (c[0]) {
            cout << 'L';
            x[i]++;
        }
        ull u = x[i] + y[i], v = x[i] - y[i];
        ull u2 = (s - u) / 2, v2 = (s - v) / 2;
        for (ull j = 0; j < 32; j++) {
            ull d1 = u2 & ((ull)1 << j) ? 0 : 1;
            ull d2 = v2 & ((ull)1 << j) ? 0 : 1;
            cout << t[d1][d2];
        }
        cout << endl;
    }
}
