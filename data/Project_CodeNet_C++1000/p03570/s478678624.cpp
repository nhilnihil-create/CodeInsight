#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = (int)s.size();
    int a = 0;

    int *c = (int *)calloc(1 << 26, 4);
    c[0] = 1;

    for (int i = 0; i < n; i++) {
        a ^= 1 << (s[i] - 'a');
        int m = n;
        for (int k = 1 << ('z' - 'a');; k >>= 1) {
            int t = c[a ^ k];
            if (t != 0 && t < m) m = t;

            if (k == 0) break;
        }

        if (i == n - 1) cout << m << endl;
        m++;

        c[a] = c[a] == 0 ? m : min(c[a], m);
    }

    return 0;
}