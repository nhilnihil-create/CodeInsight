#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L


int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n-1; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        x--;y--;
        g[x].push_back(make_pair(y, k));
        g[y].push_back(make_pair(x, k));
    }
    pair<int,int> start = g[0][0];
    queue<pair<int, int>> q;
    q.push(start);
    vector<bool> visited(n);
    visited[start.first] = true;
    vector<int> color(n);
    while (!q.empty()) {
        pair<int,int> pp = q.front();
        q.pop();
        int u = pp.first;
        for (auto v : g[u]) {
            int y = v.first;
            if (visited[y]) continue;
            int length1 = v.second;
            q.push(v);
            if (length1 % 2 == 0) color[y] = color[u];
            else color[y] = color[u] ^ 1;
            visited[y] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << color[i] << "\n";
    }


    return 0;
}