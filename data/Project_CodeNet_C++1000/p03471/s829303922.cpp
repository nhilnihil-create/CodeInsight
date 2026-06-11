#include <math.h>

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    // int n;
    // cin >> n;
    // int a[n];
    // sort(a, a + n);
    // int len = 0;
    // for (int i = 0; i < n; i++) cin >> a[i];
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         for (int k = j + 1; k < n; k++) {
    //             if (a[i] + a[j] > a[k]) len = max(len, a[i] + a[j] + a[k]);
    //         }
    //     }
    // }
    // cout << len << endl;

    // int n;
    // cin >> n;
    // int x[n], y[n];
    // double dist = 0.0;
    // for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         dist = max(dist, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j],
    //         2)));
    //     }
    // }
    // cout << dist << endl;

    // int k, s;
    // cin >> k >> s;
    // int count = 0;
    // for (int x = 0; x <= k; x++) {
    //     for (int y = 0; y <= k; y++) {
    //         int z = s - x - y;
    //         if (z >= 0 && z <= k) count++;
    //     }
    // }
    // cout << count << endl;

    int n, y;
    cin >> n >> y;
    bool trueth = false;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            if (10000 * i + 5000 * j + 1000 * (n - i - j) == y) {
                cout << i << " " << j << " " << (n - i - j) << endl;
                trueth = true;
                break;
            }
        }
        if (trueth) break;
    }
    if (!trueth) cout << "-1 -1 -1" << endl;
    return 0;
}