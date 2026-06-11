#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

vector<vector<int>> g(200200);
pair<int, int> tdfs(int v, int p) {
    pair<int, int> d = make_pair(1, v);
    for (auto u : g[v])
        if (u != p) {
            pair<int, int> d2 = tdfs(u, v);
            d2.first++;
            d = max(d, d2);
        }
    return d;
}

int treediameter() {
    return tdfs(tdfs(0, -1).second, -1).first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(10);

    int n;
    cin >> n;

    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    // cout << treediameter() << endl;
    int x = treediameter();
    if (x % 3 == 2)
        cout << "Second" << endl;
    else
        cout << "First" << endl;

    return 0;
}