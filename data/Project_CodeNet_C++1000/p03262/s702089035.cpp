#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, X;
    int x[100000];
    cin >> n >> X;
    for (int i = 0; i < n; i++) cin >> x[i];

    int ans = abs(X - x[0]);
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, abs(X - x[i]));
    }

    cout << ans << endl;
}