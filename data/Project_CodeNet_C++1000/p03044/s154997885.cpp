#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<pair<long long, long long>> T[N + 1];
    for (long long i = 1; i <= N - 1; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        T[u].push_back(make_pair(v, w));
        T[v].push_back(make_pair(u, w));
    }
    stack<pair<long long, long long>> S;
    vector<long long> ans(N + 1);
    vector<long long> col(N + 1, 0);
    S.push(make_pair(1, 0));
    col[1] = 1;
    while (!S.empty()) {
        auto u = S.top();
        S.pop();
        ans[u.first] = u.second % 2;
        for (auto v : T[u.first]) {
            if (col[v.first] == 0) {
                S.push(make_pair(v.first, u.second + v.second));
                col[v.first] = 1;
            }
        }
    }
    for (long long i = 1; i <= N; i++) cout << ans[i] << endl;
    return 0;
}
