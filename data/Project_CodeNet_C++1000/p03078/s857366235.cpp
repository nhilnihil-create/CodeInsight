#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vll a(x), b(y), c(z);
    rep(i, 0, x) { cin >> a[i]; }
    rep(i, 0, y) { cin >> b[i]; }
    rep(i, 0, z) { cin >> c[i]; }

    vll ab(x * y);
    rep(i, 0, x) {
        rep(j, 0, y) { ab[i + j * y] = a[i] + b[j]; }
    }

    sort(all(ab), greater<ll>());
    sort(all(c), greater<ll>());

    vll abc(min(k, x * y) * z);
    rep(i, 0, min(k, x * y)) {
        rep(j, 0, z) { abc[i + j * min(k, x * y)] = ab[i] + c[j]; }
    }
    sort(all(abc), greater<ll>());

    rep(i, 0, k) { cout << abc[i] << endl; }

    return 0;
}