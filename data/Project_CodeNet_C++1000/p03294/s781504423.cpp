#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, b % a);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

signed main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    // int b = 1;
    int ans = 0;
    // rep(i, 0, n) b = lcm(a[i], b);
    rep(i, 0, n) ans += a[i] - 1;
    cout << ans << "\n";
}