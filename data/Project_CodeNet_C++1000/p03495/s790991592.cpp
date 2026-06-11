#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N, K;
    cin >> N >> K;

    map<int, int> mp;
    rep(i, N) {
        int a;
        cin >> a;
        ++mp[a];
    }

    priority_queue<int, vector<int>, greater<int>> que;
    for (auto p : mp)
        que.push(p.second);

    int ans = 0;
    K = mp.size() - K;

    rep(i, K) ans += que.top(), que.pop();

    cout << ans << endl;

    return 0;
}