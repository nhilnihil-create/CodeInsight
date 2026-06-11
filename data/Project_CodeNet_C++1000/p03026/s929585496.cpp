#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<vector<int>> tree;
vector<int> c;

void dfs(int u, int p, int& idx, vector<int>& ans) {
    idx++;
    ans[u] = c[idx];
    for (int v : tree[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u, idx, ans);
    }
}

int main() {
    int N;
    cin >> N;
    tree.resize(N);
    c.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    sort(c.begin(), c.end(), greater<int>());
    vector<int> ans(N);
    int idx = -1;
    dfs(0, -1, idx, ans);

    ll sum = 0;
    for (int i = 1; i < N; i++) {
        sum += c[i];
    }
    cout << sum << endl;
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
