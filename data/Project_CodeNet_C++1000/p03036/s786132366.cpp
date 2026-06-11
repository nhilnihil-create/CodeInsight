#include <bits/stdc++.h>

using namespace std;

int main() {
    long r = 0, D = 0, x = 0, ans = 0;
    cin >> r >> D >> x;

    for (int i = 0; i < 10; ++i) {
        ans = r * x - D;
        cout << ans << endl;
        x = ans;
    }
}