#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

bool solve() {
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> s(N);
    for ( int i = 0; i < N; i++ ) {
        s[i] = (S[i] == 'B' ? 1 : 0);
    }
    int a, b;
    vector<vector<int>> G(N);
    vector<vector<int>> nc(N, vector<int>(2));
    for ( int i = 0; i < M; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        if ( a != b ) G[b].push_back(a);
        nc[a][s[b]]++;
        if ( a != b ) nc[b][s[a]]++;
    }
    auto get_m = [&](int i) {
        return min(nc[i][0],nc[i][1]);
    };
    queue<int> q;
    for ( int i = 0; i < N; i++ ) {
        if ( get_m(i) == 0 ) q.push(i);
    }
    vector<int> ng(N);

    while ( !q.empty() ) {
        int i = q.front();
        q.pop();
        if ( ng[i] > 0 ) continue;
        for ( int u : G[i] ) {
            if ( ng[u] > 0 ) continue;
            if ( u != i ) {
                nc[u][s[i]]--;
                if ( get_m(u) == 0 ) q.push(u);
            }
        }
        ng[i] = 1;
    }
    bool ans = false;
    for ( int i = 0; i < N; i++ ) {
        if ( ng[i] == 0 ) ans = true;
    }
    return ans;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}