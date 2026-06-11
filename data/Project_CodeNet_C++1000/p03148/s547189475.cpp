#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> sushi(n);
    rep(i, n) cin >> sushi[i].second >> sushi[i].first;
    sort(sushi.begin(), sushi.end());

    vector<bool> type_set(n + 1, false);
    stack<int> to_del;
    ll sum = 0, type = 0;
    for (int i = n - 1; i >= n - k; i--) {
        sum += sushi[i].first;
        if (type_set[sushi[i].second]) {  // second (or more) times to see this type
            to_del.push(sushi[i].first);
        } else {  // first time to see this type
            type_set[sushi[i].second] = true;
            type++;
        }
    }
    ll ans = sum + type * type;
    for (int i = n - k - 1; i >= 0; i--) {
        if (type_set[sushi[i].second]) continue;
        // i th sushi is the type never seen
        if (to_del.empty()) continue;
        // and there's some sushi that shares the same type
        sum -= to_del.top();
        to_del.pop();
        sum += sushi[i].first;
        type_set[sushi[i].second] = true;
        type++;
        ans = max(ans, sum + type * type);
    }
    cout << ans << endl;
}