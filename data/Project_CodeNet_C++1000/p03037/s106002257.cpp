#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int l, r;
    int max_l, min_r;
    max_l = 0;
    min_r = n;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        max_l = max(max_l, l);
        min_r = min(min_r, r);
    }
    if (min_r - max_l < 0) {
        cout << 0 << endl;
    }
    else {
        cout << min_r - max_l + 1 << endl;
    }
    return 0;
}