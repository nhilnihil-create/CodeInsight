#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define REP(i, n) for (long long i = 0; i < (n); i++)
const ll INF = 1LL << 60;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
};
signed main() {
    int a, b, x;
    cin >> a >> b >> x;
    if (x <= a + b && a <= x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}