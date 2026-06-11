#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int N; cin >> N;
    vector<vector<int>> G(N+1);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> C(N);
    for (auto& c : C) cin >> c;
    sort(C.begin(), C.end(), greater<int>());

    if (N == 1) {
        cout << C[0] << endl << C[0] << endl;
        return 0;
    }

    int sum = accumulate(C.begin()+1, C.end(), 0);
    vector<int> ans(N+1);

    vector<bool> done(N+1, false);
    queue<int> q;
    q.push(1);
    done[1] = true;
    auto it = C.begin();
    while (!q.empty()) {
        int v = q.front(); q.pop();
        ans[v] = *it++;
        for (int u : G[v]) {
            if (!done[u]) {
                q.push(u);
                done[u] = true;
            }
        }
    }

    cout << sum << endl;
    cout << ans[1];
    for (int i = 2; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
}
