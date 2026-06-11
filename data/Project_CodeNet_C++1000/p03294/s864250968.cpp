#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    ll a[3000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] - 1;
    cout << ans << endl;
}
