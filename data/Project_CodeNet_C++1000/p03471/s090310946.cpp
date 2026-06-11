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

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n, yen;
    cin >> n >> yen;
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            int x = i * 10000;
            int y = j * 5000;
            int baki = yen - x - y;
            if (baki < 0) {
                continue;
            }
            if (baki == 0 && i + j == n) {
                cout << i << " " << j << " " << 0 << '\n';
                return 0;
            }
            if (baki % 1000) {
                continue;
            }
            int b = baki / 1000;
            if (i + j + b == n) {
                cout << i << " " << j << " " << b << '\n';
                return 0;
            }
        }
    }
    cout << "-1 -1 -1\n";
    return 0;
}
