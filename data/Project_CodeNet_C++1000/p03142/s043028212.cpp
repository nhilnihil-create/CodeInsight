#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> cnt(N, 0);
    rep(i, N - 1 + M) {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        G[A].push_back(B);
        ++cnt[B];
    }
    
    vector<int> par(N, -1);
    queue<int> q;
    rep(i, N) {
        if (cnt[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            --cnt[v];
            if (cnt[v] == 0) q.push(v);
            par[v] = u;
        }
    }
    rep(i, N) cout << par[i] + 1 << "\n";
    return 0;
}

