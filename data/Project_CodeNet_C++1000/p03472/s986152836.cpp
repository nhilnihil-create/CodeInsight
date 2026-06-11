#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll  long long
#define PR  pair<int, int>

const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
const long long INF = 5e18;
const double PI = 2 * acos(0.0);
//template<typename T> using ordered_set = tree<T, nulong long_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + n + 1, greater<ll>());
    sort(b + 1, b + n + 1, greater<ll>());
    ll ans = h / a[1];
    if (h % a[1]) {
        ans++;
    }
    for (int i = 1; i <= n; i++) {
        h -= b[i];
        if (h <= 0) {
            ans = min(ans, (ll)i);
            continue;
        }
        ll now = h / a[1];
        if (h % a[1]) {
            now++;
        }
        now += i;
        ans = min(ans, now);
    }
    cout << ans << '\n';
    return 0;
}
