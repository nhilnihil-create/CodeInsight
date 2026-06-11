#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << endl
#define Int int64_t
#define fi first
#define se second

Int INF = 1e9;
Int mod = 1e9+7;

int main() {
    Int n;
    cin >> n;
    char a[301][301];
    for (Int i = 0; i < n; i++) {
        for (Int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    Int res = 0;
    bool check = true;
    for (Int k = 0; k < n; k++) {
        // cout << endl;
        // for (Int i = 0; i < n; i++) {
        //     for (Int j = 0; j < n; j++) {
        //         cout << a[i][(j + k) % n];
        //     }
        //     cout << endl;
        // }
        check = true;
        for (Int i = 0; i < n - 1; i++) {
            for (Int j = i + 1; j < n; j++) {
                //cout << a[i][(j + k) % n] << " " << a[j][(i + k) % n] << endl;
                if (a[i][(j + k) % n] != a[j][(i + k) % n]) {
                    check = false;
                }
            }
        }
        if (check) {
            res++;
        }
    }
    dump(res * n);
    return 0;
}