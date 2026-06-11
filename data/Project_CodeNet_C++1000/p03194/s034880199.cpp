#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, p;
    cin >> n >> p;

    if (n == 1) {
        cout << p << endl;
        return 0;
    }

    long ans = 1;

    long i = 1;
    while (1) {
        i++;

        long ss = 1;
        for (long j = 0; j < n; j++) {
            ss *= i;
            if (ss > p) {
                break;
            }
        }

        if (ss > p) {
            break;
        }

        if (p % ss == 0) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
