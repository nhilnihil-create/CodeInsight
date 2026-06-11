#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long int lli;

lli power(int x, lli n) {
    if (n == 0) return 1;

    if (n == 1) return x;

    if (n & 1) {
        lli t = power(x, n >> 1);
        return t * t * x;
    } else {
        lli t = power(x, n >> 1);
        return t * t;
    }
}

int main() {
    lli N, P;
    cin >> N >> P;

    if (N == 1) {
        cout << P << endl;
        return 0;
    }

    if (N >= 40) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 1; true; i++) {
        lli t = power(i, N);
        if (t > P) break;
        if (P % t == 0) ans = i;
    }

    cout << ans << endl;
}
