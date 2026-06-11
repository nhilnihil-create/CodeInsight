#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int k, n;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h, h + n);
    int ans = 1e9;
    for (int i = 0; i + k - 1 < n; i++) {
        ans = min(ans, h[i + k - 1] - h[i]);
    }
    printf("%d\n", ans);
}