#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (n & 1 && j == n - i) continue;
            if (!(n & 1) && j == n - i + 1) continue;
            edges.push_back({i, j});
        }
    }
    cout << edges.size() << endl;
    for (auto v : edges) {
        cout << v[0] << " " << v[1] << endl;
    }
}