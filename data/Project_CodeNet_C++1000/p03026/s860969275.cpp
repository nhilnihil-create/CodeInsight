#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int to;
    int num;
} edge;
typedef long long ll;

void dfs(int s, vector<ll> &c, vector<vector<int> > &G, int &i, vector<int> &ans) {
    ans[s] = c[i];
    i++;
    for (auto u: G[s]) {
        if (ans[u] != -1)
            continue;

        dfs(u, c, G, i, ans);
    }
}

int main() {
    int n;  cin >> n;
    vector<int> ans(n, -1);
    vector<vector<int> > G(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;   cin >> a >> b;  a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c.begin(), c.end(), greater<ll>());
    ll sum = 0;
    for (int i = 1; i < n; i++)
        sum += c[i];
    cout << sum << endl;


    int i = 0;
    dfs(0, c, G, i, ans);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}