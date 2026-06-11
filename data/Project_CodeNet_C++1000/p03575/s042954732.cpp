#include "bits/stdc++.h"

using namespace std;

vector<int> parents;
vector<int> ranks;

void init(int n) {
    parents = vector<int>(n, 0);
    ranks = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }
}

int find(int x) {
    if (parents[x] == x) {
        return x;
    }
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    if (ranks[x] > ranks[y]) {
        parents[y] = x;
    }
    else if (ranks[y] > ranks[x]) {
        parents[x] = y;
    }
    else {
        parents[x] = y;
        ++ranks[x];
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void Main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M, make_pair(0, 0));
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edges[i] = make_pair(a, b);
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        init(N);
        for (int j = 0; j < M; ++j) {
            if (i == j) {
                continue;
            }
            unite(edges[j].first, edges[j].second);
        }
        bool connected = true;
        for (int j = 1; j < N; ++j) {
            if (!same(0, j)) {
                connected = false;
                break;
            }
        }
        if (!connected) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
