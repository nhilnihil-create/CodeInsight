#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, smx = 0;
    cin >> n;
    bitset<(int)4e6 + 1> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        smx += a;
        dp |= dp << a;
    }
    for (int i = (smx + 1) / 2; i <= smx; i++) {
        if (dp[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}