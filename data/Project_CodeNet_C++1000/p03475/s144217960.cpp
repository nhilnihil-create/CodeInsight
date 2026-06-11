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
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n), s(n), f(n);
    for (int i = 0; i < n- 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int ans = s[i] + c[i];
        for (int j = i + 1; j < n - 1; j++) {
            int tmp = ans;
            if (tmp >= s[j]) {
                tmp %= f[j];
                if (tmp == 0) {
                    ans += c[j];
                } else {
                    int need = f[j] - tmp;
                    ans += need;
                    ans += c[j];
                }
            } else {
                ans += (s[j] - ans);
                ans += c[j];
            }
        }
        cout << ans << '\n';
    }
    cout << "0\n";
    return 0;
}
