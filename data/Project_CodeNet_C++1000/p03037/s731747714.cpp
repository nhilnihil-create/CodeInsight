#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int l, r, max_l = 0, min_r = 100001;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        if (l > max_l) max_l = l;
        if (r < min_r) min_r = r;
    }

    if (min_r < max_l) {
        cout << 0 << endl;
    } else {
        cout << min_r - max_l + 1 << endl;
    }

    return 0;
}
