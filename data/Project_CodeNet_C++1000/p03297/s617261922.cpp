#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        // cant tolerate the very first day
        if (a < b) {
            cout << "No" << endl;
            continue;
        }
        // cant keep up with the buy
        if (b > d) {
            cout << "No" << endl;
            continue;
        }
        // the threshold is too high; cant buy more than the stock
        if (b < c) {
            cout << "Yes" << endl;
            continue;
        }
        ll g = gcd(b, d);
        ll thrs = b - g + (a % g);
        puts(thrs > c ? "No" : "Yes");
    }
}