#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    int ans = 1, diff = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) diff *= 2;
        ans *= 3;
    }
    ans -= diff;
    cout << ans << endl;
}