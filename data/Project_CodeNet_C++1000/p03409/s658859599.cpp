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

PR a[N], b[N];
vector<int> g[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i].first >> b[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i].first < b[j].first && a[i].second < b[j].second) {
                g[i].push_back(n + j);
                cnt[n + j]++;
            }
        }
    }
    vector<int> go;
    for (int i = 1; i <= n; i++) {
        go.push_back(i);
        sort(g[i].begin(), g[i].end(), [](int &x, int &y) {
            return cnt[x] < cnt[y];
        });
    }
    sort(go.begin(), go.end(), [](int &x, int &y) {
        return g[x].size() < g[y].size();
    });
    int ans = 0;
    map<int, int> vis;
    for (auto i : go) {
        for (auto v : g[i]) {
            if (vis[v] == 0) {
                ans++;
                vis[v] = 1;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
