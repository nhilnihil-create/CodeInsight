#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    c.PB(x);
    sort(c.begin(), c.end());
    vector<int> d;
    for (int i = 1; i <= n; ++i) {
        d.PB(c[i] - c[i - 1]);
    }
    if (d.size() == 1) cout << d.front() << "\n";
    else {
        int ans = gcd(d[0], d[1]);
        for (int i = 1; i < n; ++i) {
            ans = gcd(ans, gcd(d[i], d[i - 1]));
        }
        cout << ans << "\n";
    }
}