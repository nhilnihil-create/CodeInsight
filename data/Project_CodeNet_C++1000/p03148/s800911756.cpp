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

    vector<bool> isused(N);
    priority_queue<int, vector<int>, greater<int>> maque;
    priority_queue<int> que;
    ll pt = 0;
    for (int i = 0; i < N; ++i) {
        if (!isused[td[i].first] && maque.size() < K) {
            maque.push(td[i].second);
            pt += td[i].second;
            isused[td[i].first] = true;
        } else
            que.push(td[i].second);
    }

    int cnt = maque.size();
    while (cnt < K) {
        pt += que.top();
        que.pop();
        cnt++;
    }

    cnt = maque.size();
    ll ans = pt + (ll)cnt * cnt;
    for (int i = cnt - 1; i > 0; --i) {
        if (maque.top() < que.top()) {
            pt += que.top();
            que.pop();
            pt -= maque.top();
            que.push(maque.top());
            maque.pop();
        }
        ans = max(ans, pt + (ll)i * i);
    }
    cout << ans << endl;
    return 0;
}
