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

    vi a(5);
    rep(i, 0, 5) { cin >> a[i]; }

    int k;
    cin >> k;

    if (a[4] - a[0] > k) {
        cout << ":(" << endl;
    }
    else {
        cout << "Yay!" << endl;
    }

    return 0;
}