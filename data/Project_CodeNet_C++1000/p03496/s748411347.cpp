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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pos = 1;
        } else if (a[i] < 0) {
            neg = 1;
        } else {
            continue;
        }
    }
    vector<PR> ans;
    if (pos && neg) {
        int mx = -1e9, mn = 1e9, pmx = 0, pmn = 0;
        for (int i = 0;  i < n; i++) {
            if (mx < a[i]) {
                mx = a[i];
                pmx = i;
            }
            if (mn > a[i]) {
                mn = a[i];
                pmn = i;
            }
        }
        if (abs(mx) >= abs(mn)) {
            neg = 0;
            for (int i = 0; i < n; i++) {
                ans.push_back({pmx + 1, i + 1});
                a[i] += a[pmx];
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.push_back({pmn + 1, i + 1});
                a[i] += a[pmn];
            }
        }
    }
    if (neg) {
        for (int i = n - 2; i >= 0; i--) {
            while (a[i] > a[i + 1]) {
                int mn = 1e9, pos = 0;
                for (int j = 0; j < n; j++) {
                    if (mn > a[j]) {
                        mn = a[j];
                        pos = j;
                    }
                }
                ans.push_back({pos + 1, i + 1});
                a[i] += a[pos];
            }
        }
    } else {
        for (int i = 1; i < n; i++) {
            while (a[i] < a[i - 1]) {
                int mx = -1e9, pos = 0;
                for (int j = 0; j < n; j++) {
                    if (mx < a[j]) {
                        mx = a[j];
                        pos = j;
                    }
                }
                ans.push_back({pos + 1, i + 1});
                a[i] += a[pos];
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << '\n';
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first << " " << i.second << '\n';
    }
    return 0;
}
