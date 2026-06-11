#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
typedef long long Int;
#define rep(i,a,b) for(Int i=a;i<b;++i)
#define rrep(i,a,b) for(Int i=a;i>=b;--i)
using namespace std;

vector<vector<Int>> graph;
Int N, U;
vector<Int> distFrom0, distFromU;

void dfs(vector<Int>& res, Int now, Int parent, Int dist) {
    res[now] = dist;

    for(auto edge : graph[now]) {
        if (edge == parent) continue;
        dfs(res, edge, now, dist+1);
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    Int N; cin >> N;
    graph.assign(N, vector<Int>());
    distFrom0.assign(N, 0);
    distFromU.assign(N, 0);

    rep(i, 0, N-1) {
        Int A, B; cin >> A >> B;
        --A, --B;
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);
    }

    dfs(distFrom0, 0, -1, 0);
    Int U = distance(distFrom0.begin(), max_element(distFrom0.begin(), distFrom0.end()));
    
    dfs(distFromU, U, -1, 0);
    Int diameter = *max_element(distFromU.begin(), distFromU.end());

    if (diameter % 3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
}