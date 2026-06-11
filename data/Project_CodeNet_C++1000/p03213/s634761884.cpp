
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, res;
int a[101];
int x3, x5, x15, x25, x75;
void init() {
    for (int i = 2; i <= n; ++i) {
        int n = i;
        while (n != 1) {
            for (int j = 2; j <= n; ++j) {
                while (n % j == 0) {
                    a[j]++;
                    n = n / j;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= 2) ++x3;
        if (a[i] >= 4) ++x5;
        if (a[i] >= 14) ++x15;
        if (a[i] >= 24) ++x25;
        if (a[i] >= 74) ++x75;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    init();
    // cout <<  x3 << ' ' << x5 << endl;

    res += x5 * (x5 - 1) / 2 * (x3 - 2);
    res += x15 * (x5 - 1);
    res += x75;
    res += x25 * (x3 - 1);
    cout << res << endl;

    return 0;
}

