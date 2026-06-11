#include "bits/stdc++.h"

using namespace std;
using pii = pair <int, int>;

const int mx = 1e5 + 9;

int clr[mx];
vector <pii> adj[mx];

void color(int u, int par = -1) {
    for (auto v : adj[u]) {
        if (v.first == par) continue;
        clr[v.first] = clr[u];
        if (v.second & 1) clr[v.first] = 1 - clr[v.first];
        color(v.first, u);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    clr[1] = 0;
    color(1);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", clr[i]);
    }
}