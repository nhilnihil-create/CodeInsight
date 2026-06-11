#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<pii> td(N);
    for (int i = 0; i < N; ++i) {
        cin >> td[i].first >> td[i].second;
        td[i].first--;
    }

    auto cmp = [&](pii a, pii b) { return a.second == b.second ? a.first < b.first : a.second > b.second; };
    sort(td.begin(), td.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> que1;
    priority_queue<int> que2;
    vector<bool> isused(N);
    int cnt = 0;
    ll pt = 0;
    for (int i = 0; i < K; ++i) {
        if (isused[td[i].first])
            que1.push(td[i].second);
        else {
            isused[td[i].first] = true;
            cnt++;
        }
        pt += td[i].second;
    }
    for (int i = K; i < N; ++i) {
        if (!isused[td[i].first]) {
            isused[td[i].first] = true;
            que2.push(td[i].second);
        }
    }

    ll ans = pt + (ll)cnt * cnt;
    while (!que1.empty() && !que2.empty()) {
        pt -= que1.top();
        pt += que2.top();
        que1.pop();
        que2.pop();
        cnt++;
        ans = max(ans, pt + (ll)cnt * cnt);
    }

    cout << ans << endl;
    return 0;
}
