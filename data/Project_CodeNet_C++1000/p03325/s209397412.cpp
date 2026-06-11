#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, ans; ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (;a % 2 != 1; a /= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}