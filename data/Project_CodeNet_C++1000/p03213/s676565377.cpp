#include <bits/stdc++.h>
using namespace std;

map < int, int > ps;

int num (int m) {
    int res = 0;
    for (auto pr: ps) {
        if (pr.second >= m - 1)
            ++res;
    }
    return res;
}

signed main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int m = i;
        for (int j = 2; j * j <= m; ++j) {
            while (m % j == 0) {
                ++ps[j];
                m /= j;
            }
        }
        if (m != 1) 
            ++ps[m];
    }
    cout << num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1) + num(5) * (num(5) - 1) * (num(3) - 2) / 2 << '\n';
}
