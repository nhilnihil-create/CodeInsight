#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

int main() {
    long n, d, ans = -1e9;
    cin >> n >> d;
    if (d >= n) {
        cout << n << endl;
    } else {
        cout << n - 1 << endl;
    }
}