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
    priority_queue<pii> q;
    auto q_push = [&](int i) {
        q.push(pii(-min(nc[i][0],nc[i][1]), i));
    };
    for ( int i = 0; i < N; i++ ) {
        q_push(i);
    }
    vector<int> ng(N);

    while ( !q.empty() ) {
        int i, m;
        auto p = q.top();
        i = p.second;
        m = -p.first;
        if ( ng[i] > 0 ) {
            q.pop();
            continue;
        }
        int mn = min(nc[i][0],nc[i][1]);
        if ( mn < m ) {
            q.pop();
            continue;
        }
        if ( m == 0 ) {
            q.pop();
            for ( int u : G[i] ) {
                if ( ng[u] > 0 ) continue;
                if ( u != i ) {
                    nc[u][s[i]]--;
                    q_push(u);
                }
            }
            ng[i] = 1;
        } else {
            break;
        }
    }
    bool ans = !q.empty();
    return ans;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}