#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M = 0;
    cin >> N;
    vector<int> a(N - 1), b(N - 1), c(N), ans(N);
    vector<vector<int>> edge(N);
    rep(i, N - 1) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }
    rep(i, N) {
        cin >> c[i];
        M += c[i];
    }
    sort(c.begin(), c.end());
    M -= c[N - 1];
    vector<bool> done(N, false);
    queue<int> q;
    q.push(0);
    done[0] = true;
    int j = N - 1;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        done[p] = true;
        ans[p] = c[j];
        //cout << "ans[" << p << "]=" << ans[p] << "\n";
        j--;
        rep(i, edge[p].size()) {
            if (done[edge[p][i]]) continue;
            q.push(edge[p][i]);
        }
    }
    cout << M << "\n";
    rep(i, N) {
        cout << ans[i];
        if (i == N - 1) cout << "\n";
        else cout << " ";
    }
}