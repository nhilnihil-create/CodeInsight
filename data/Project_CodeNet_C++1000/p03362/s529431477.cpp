#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

bool prime (int i) {
    if (i == 1) return false;
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) return false;
    }
    return true;
}

signed main() {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 2; vec.size() < n; i++) {
        if (prime (i) && i % 5 == 1) {
            vec.push_back (i);
        }
    }
    rep (i, 0, n) cout << vec[i] << " ";
    cout << "\n";
}