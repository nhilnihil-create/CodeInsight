#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;

bool ok[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int n = s.length();
    s = " " + s;

    bool gd = true;
    for (int i = 1; i <= n - 1; i++) {
        gd &= s[i] == s[n - i];
    }
    gd &= s[1] == '1' && s[n] == '0';
    if (!gd) {
        cout << -1 << endl;
        return 0;
    }

    s[n] = '1';

    int nxt = 0;
    for (int i = 1; i < n; i++) {
        while (nxt <= i || s[nxt] == '0')
            nxt++;
        cout << i << " " << nxt << endl;
    }
}