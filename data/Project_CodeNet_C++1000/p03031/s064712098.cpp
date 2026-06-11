#include "bits/stdc++.h"

using i64 = long long;
#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 (Itr) = a; (Itr) < b; (Itr) += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

using namespace std;
using llong = long long;

int main() {
    int n, m;
    int k[16];
    int s[16][16];
    int p[16];

    cin >> n >> m;
    repeat(i, m) {
        cin >> k[i];
        repeat(j, k[i]) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    repeat(i, m) {
        cin >> p[i];
    }

    int ans = 0;
    repeat(i, 1 << n) {
        bitset<16> st(i);

        int cnt = 0;
        repeat(j, m) {
            int a = 0;
            repeat(it, k[j]) {
                a ^= st[s[j][it]] & 1;
            }

            if (a == p[j]) cnt++;
        }

        if (cnt == m) ans++;
    }

    cout << ans << endl;

    return 0;
};
