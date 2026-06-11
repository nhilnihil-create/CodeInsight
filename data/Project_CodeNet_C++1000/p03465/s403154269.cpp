#include <bits/stdc++.h>

using namespace std;

int n;
int v[2001];
bitset <4000001> b;

inline void getBit() {
    b[0] = 1;
    for (int i = 1; i <= n; ++i)
        b |= (b << v[i]);
    int MAX = 0;
    for (int i = 1; i <= n; ++i)
        MAX += v[i];
    int p = (MAX >> 1) + (MAX & 1);
    while (p && !b[p])
        ++p;
    cout << p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    getBit();
    return 0;
}
