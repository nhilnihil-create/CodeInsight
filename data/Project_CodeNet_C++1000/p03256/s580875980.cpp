#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N, M; cin >> N >> M;
    string S; cin >> S;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        if (a != b) G[b].push_back(a);
    }
    vector<bool> okay(N, true), visited(N);
    auto recur = [&](auto rec, int i, vector<int>& A) -> void {
        if (visited[i]) return;
        visited[i] = true;
        if (!okay[i]) return;
        for (int next : G[i]) rec(rec, next, A);
        A.push_back(i);
        int a = 0;
        for (int next : G[i]) {
            if (okay[next] && S[next] == 'A') a |= 1;
            if (okay[next] && S[next] == 'B') a |= 2;
            if (a == 3) break;
        }
        okay[i] = a == 3;
    };
    vector<int> A, B;
    int n = 10;
    A.resize(N); iota(begin(A), end(A), 0);
    while (n--) {
        vector<int> B;
        fill(begin(visited), end(visited), false);
        for (auto i : A) recur(recur, i, B);
        swap(A, B);
    }
    bool ans = false;
    for (auto a : okay) ans |= a;
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}