#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!(a & 1)) {
            a /= 2;
            ans++;
        }
    }

    cout << ans << endl;
}