#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, cnt = 0; cin >> n >> m;
    priority_queue<int64_t, vector<int64_t>, greater<>> q;
    vector<pair<int64_t, int>> b(m); int64_t ans = 0;
    for (auto i = 0; i < n; i++) { int a; cin >> a; q.push(a); ans += a; }
    for (auto i = 0; i < m; i++) cin >> b[i].second >> b[i].first;
    sort(b.begin(), b.end(), greater<>());
    for (auto & elm : b) {
        for (auto i = 0; i < elm.second; i++) {
            auto p = q.top(); q.pop();
            if(p < elm.first) { ans = ans - p + elm.first; p = elm.first; q.push(p); cnt++; }
            else break;
        }
        if(cnt > n) break;
    }
    cout << ans << endl;
    return 0;
}