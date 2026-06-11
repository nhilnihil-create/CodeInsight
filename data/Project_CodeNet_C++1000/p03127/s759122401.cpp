#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5;
int n;
int a[N];
int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int p = a[0];
    for (int i = 1; i < n; ++i) {
        p = gcd(p, a[i]);
    }
    cout << p << endl;

    return 0;
}

// 4 7 49