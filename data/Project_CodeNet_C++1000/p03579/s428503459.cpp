#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    Int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> color(N);
    bool stop = false;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    function<void(int, int)> recur = [&](int node, int c) {
        if (color[node] == c) return;
        if (color[node] == -c) stop = true;
        if (stop) return;
        color[node] = c;
        for (auto next : G[node]) recur(next, -c);
    };
    recur(0, +1);
    if (stop) {
        cout << N * (N-1) / 2 - M << endl;
    } else {
        int a = 0;
        for (auto c : color) if (c == +1) a++;
        cout << a * (N - a) - M << endl;
    }
    return 0;
}