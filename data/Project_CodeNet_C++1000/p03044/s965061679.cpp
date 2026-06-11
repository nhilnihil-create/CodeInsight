#include <bits/stdc++.h>

typedef long long ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl '\n'
const int N = 1e5 + 10;
using namespace std;
int n;
ll colour[N];
vector<pair<int, int>> a[N];

void dfs(int u, int p) {
    for (auto child:a[u]) {
        if (child.first == p) continue;
        colour[child.first] = colour[u] + child.second;
        dfs(child.first, u);
    }
}

int main() {
    IO;
    cin >> n;
    int u, v, w;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        cout << colour[i] % 2 <<endl;
    }


}
