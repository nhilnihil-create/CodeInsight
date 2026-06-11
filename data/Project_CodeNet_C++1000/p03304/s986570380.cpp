#include <bits/stdc++.h>

using namespace std;

int main() {
    double n, m, d;
    cin >> n >> m >> d;

    cout << fixed << setprecision(10);
    if (d == 0) {
        cout << (m - 1.0) / n << endl;
    } else {
        cout << 2.0 * (n - d) / n / n * (m - 1) << endl;
    }
    return 0;
}