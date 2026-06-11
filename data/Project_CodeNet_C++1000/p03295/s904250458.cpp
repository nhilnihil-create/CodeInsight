#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> order(M);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        order[i] = make_pair(b, a);
    }

    sort(order.begin(), order.end());

    int ans = 1;
    int cut = 0;
    for (int i = 1; i < M; i++) {
        if (order[i].second < order[cut].first) continue;
        cut = i;
        ans++;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}