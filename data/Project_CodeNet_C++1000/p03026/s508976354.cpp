#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 1e4 + 5;

vector<int> g[N];
int deg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> c(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ans += c[i];
    }
    sort(c.begin(), c.end());
    ans -= c[n - 1];

    vector<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            leaves.push_back(i);
        }
    }

    int cur = 0;
    vector<int> col(n + 1);
    for (int i = 0; i < leaves.size(); i++) {
        col[leaves[i]] = c[cur++];
        for (int j : g[leaves[i]]) {
            if (--deg[j] == 1) {
                leaves.push_back(j);
            }
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << col[i] << " \n"[i == n];
    }
    return 0;
}