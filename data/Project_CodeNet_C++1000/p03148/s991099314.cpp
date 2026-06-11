#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, int>> sushis;
    for (int i = 0; i < n; i++) {
        int t;
        ll d;
        cin >> t >> d;
        sushis.push_back({d, t});
    }
    sort(sushis.begin(), sushis.end());
    reverse(sushis.begin(), sushis.end());
    ll cur = 0;
    vector<bool> aleady(n + 1, false);
    priority_queue<ll, vector<ll>, greater<ll>> can_reduce;
    ll count = 0;
    for (int i = 0; i < k; i++) {
        ll d = sushis[i].first;
        int t = sushis[i].second;
        cur += d;
        if (aleady[t]) {
            can_reduce.push(d);
        } else {
            aleady[t] = true;
            count++;
        }
    }
    ll ans = cur + count * count;
    for (int i = k; i < n; i++) {
        int t = sushis[i].second;
        if (aleady[t])
            continue;
        if (can_reduce.empty() || count >= k)
            break;
        count++;
        auto top = can_reduce.top();
        can_reduce.pop();
        cur += -top + sushis[i].first;
        ans = max(ans, cur + count * count);
        aleady[t] = true;
    }
    cout << ans;
    return 0;
}
