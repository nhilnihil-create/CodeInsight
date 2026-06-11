// 7/12
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> x(N);
    rep(i, N) cin >> x[i];
    x.push_back(X);

    sort(x.begin(), x.end());

    vector<int> y;
    rep(i, N) y.push_back(x[i+1]-x[i]);

    int l = y.size();
    if (l == 1) {
        cout << y[0] << endl;
        return 0;
    }

    // cout << "l: " << l << endl;
    // cout << "here?" << endl;
    int d = gcd(y[0], y[1]);
    for (int i = 2; i < l; i++) {
        // cout << "here?" << endl;
        d = gcd(d, y[i]);
    }

    cout << d << endl;
    return 0;
}