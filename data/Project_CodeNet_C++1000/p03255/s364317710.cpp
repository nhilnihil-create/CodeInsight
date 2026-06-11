//
//  Created by Ruslan Jankurazov.
//  Copyright © 2018 Ruslan Jankurazov. All rights reserved.
//

#pragma GCC optimize("Ofast")

#include "bits/stdc++.h"

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define f first
#define s second
#define uint unsigned int

using namespace std;

ll a[200500];
ull d[200500];
ll n, x;

int main() {
#define FILE_INPUT 0
#define FILE ""
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if FILE_INPUT == 1
#warning "FREOPEN is on"
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
#endif
#endif
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }
    // 5x
    // (2i + 1) * x;
    ull ans = 2e18;
    for (int k = 1; k <= n; ++k) {
        ull res = 0;
        int r = (int)n;
        ull e = 1;
        while (r) {
            int l = max(0, r - k);
            if (e == 1) {
                res += 5 * (d[r] - d[l]);
            } else {
                res += (2ll*e + 1)*(d[r] - d[l]);
            }
            r = l;
            e++;
        }
        //cout << res << ' ';
        ans = min(res + k*x, ans);
    }
    cout << ans + n*x;
    return 0;
}
