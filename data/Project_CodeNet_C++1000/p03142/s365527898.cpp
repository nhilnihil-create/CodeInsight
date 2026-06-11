#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int in_degree[100005];

vector<int> edges[100005];

int parent[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        in_degree[b]++;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: edges[cur]) {
            in_degree[nxt]--;
            if (in_degree[nxt] == 0) {
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << endl;
    }
}
