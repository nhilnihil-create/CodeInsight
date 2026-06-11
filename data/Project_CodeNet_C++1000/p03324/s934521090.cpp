#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, N;
    cin >> D >> N;

    int ans;
    if (N < 100) {
        if (D == 0) ans = N;
        else if (D == 1) ans = 100 * N;
        else ans = 10000 * N;
    } else {
        if (D == 0) ans = N + 1;
        else if (D == 1) ans = 100 * (N + 1);
        else ans = 10000 * (N + 1);
    }

    cout << ans << endl;
}