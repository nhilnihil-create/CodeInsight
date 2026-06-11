#include "bits/stdc++.h"

using namespace std;

vector<int> parents;
vector<int> sizes;

void init(int n) {
    parents = vector<int>(n, 0);
    sizes = vector<int>(n, 1);
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

    if (sizes[x] < sizes[y]) {
        parents[x] = y;
    }
    else { // if (sizes[x] >= sizes[y]) {
        parents[y] = x;
    }
    int total = sizes[x] + sizes[y];
    sizes[x] = total;
    sizes[y] = total;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void Main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        --p[i];
    }
    init(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        unite(x, y);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (same(i, p[i])) {
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
