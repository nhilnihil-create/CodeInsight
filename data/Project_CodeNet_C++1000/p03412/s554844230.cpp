#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;
typedef long long li;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    li n;
    cin >> n;
    vector<li> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> ys[i];
    }

    li ans = 0;
    for (int b = 0; b < 29; ++b) {
        const li mask = (1LL << (b + 1)) - 1;
        vector<li> subxs(n), subys(n);
        for (int i = 0; i < n; ++i) {
            subxs[i] = xs[i] & mask;
            subys[i] = ys[i] & mask;
        }

        sort(subys.begin(), subys.end());
        const li unit = 1LL << b;
        li bits = 0;
        for (int xp = 0; xp < n; ++xp) {
            bits += (lower_bound(subys.begin(), subys.end(), 2 * unit - subxs[xp]) -
                    lower_bound(subys.begin(), subys.end(), 1 * unit - subxs[xp]));
            bits += (lower_bound(subys.begin(), subys.end(), 4 * unit - subxs[xp]) -
                    lower_bound(subys.begin(), subys.end(), 3 * unit - subxs[xp]));
        }
        ans += (bits & 1) * unit;
    }
    cout << ans << endl;
    return 0;
}
