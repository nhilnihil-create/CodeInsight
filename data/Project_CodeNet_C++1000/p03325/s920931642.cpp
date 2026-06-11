#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a[10000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            ans++;
        }
    }

    cout << ans << endl;
}
