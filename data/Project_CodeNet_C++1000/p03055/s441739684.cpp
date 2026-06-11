#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
typedef long long Int;
#define rep(i,a,b) for(Int i=a;i<b;++i)
#define rrep(i,a,b) for(Int i=a;i>=b;--i)
using namespace std;

vector<vector<long long>> graph;

void dfs(long long now, long long parent, long long dist, long long& maxDist, long long& farthestNode) {
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = now;
    }

    for(auto next : graph[now]) {
        if (next == parent) continue;
        dfs(next, now, dist+1, maxDist, farthestNode);
    }
}

void TreeDiameter(long long& diameter, long long& from, long long& to) {
    long long maxDist = -1, farthestNode = -1;
    dfs(0, -1, 0, maxDist, farthestNode);
    from = farthestNode;
    maxDist = 0;
    dfs(from, -1, 0, maxDist, farthestNode);
    to = farthestNode;
    diameter = maxDist;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    long long N; cin >> N;
    graph.assign(N, vector<long long>());

    for(long long i = 0; i < N-1; ++i) {
        long long A, B; cin >> A >> B;
        --A, --B;
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);
    }

    long long diameter = -1, from = -1, to = -1;
    TreeDiameter(diameter, from, to);

    if (diameter % 3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
}
