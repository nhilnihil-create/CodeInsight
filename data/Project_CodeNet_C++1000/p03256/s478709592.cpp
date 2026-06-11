#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

string s;
char t[5] = "AABB";
int r = 0;

struct Graph {
    struct Vertex { int n, p[4]; };
    struct Edge { int i, n; };
    Graph(int n, int m) : v(n, { -1, { 0, 0, 0, 0 } }), e(m), n(n), m(0) {}
    void add_edge(int i, int j) {
        e[m] = { j, v[i].n };
        v[i].n = m;
        m++;
    }
    void dfs(int i, int x) {
        if (s[i] != t[x]) return;
        if (v[i].p[x]) {
            if (v[i].p[x] & 2) r = 1;
            return;
        }
        v[i].p[x] = 3;
        for (int j = v[i].n; j >= 0; j = e[j].n) {
            Edge& o = e[j];
            dfs(o.i, (x + 1) % 4);
        }
        v[i].p[x] = 1;
    }
    vector<Vertex> v;
    vector<Edge> e;
    int n, m;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cin >> s;

    Graph g(n, m * 2);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        g.add_edge(a, b);
        g.add_edge(b, a);
    }

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 4; x++) {
            g.dfs(i, x);
        }
    }

    cout << (r ? "Yes" : "No") << endl;

    return 0;
}