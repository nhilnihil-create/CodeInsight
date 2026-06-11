#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) (void(0))
#endif  // LOCAL

bool isconnected(vector<vector<int>> &adj) {
    stack<int> st;
    vector<bool> visited(adj.size(), false);
    st.push(0);
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (auto nv : adj[v]) {
            if (!visited[nv]) {
                st.push(nv);
                visited[nv] = true;
            }
        }
    }
    return all_of(visited.begin(), visited.end(), [](int x) { return x; });
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> as(M), bs(M);
    vector<vector<int>> adj(N, vector<int>(0));
    for (int i = 0; i < M; i++) {
        cin >> as[i] >> bs[i];
        as[i]--; 
        bs[i]--;
        adj[as[i]].push_back(bs[i]);
        adj[bs[i]].push_back(as[i]);
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        adj[as[i]].erase(find(adj[as[i]].begin(), adj[as[i]].end(), bs[i]));
        adj[bs[i]].erase(find(adj[bs[i]].begin(), adj[bs[i]].end(), as[i]));
        ans += 1 - isconnected(adj);
        adj[as[i]].push_back(bs[i]);
        adj[bs[i]].push_back(as[i]);
    }

    cout << ans;

    return 0;
}