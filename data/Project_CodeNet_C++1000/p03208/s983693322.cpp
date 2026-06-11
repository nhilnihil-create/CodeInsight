#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int h[100000];
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];

    sort(h, h + n);

    int ans = 1000000000;
    for (int i = k - 1; i < n; i++) {
        ans = min(ans, h[i] - h[i - k + 1]);
    }

    cout << ans << endl;
}