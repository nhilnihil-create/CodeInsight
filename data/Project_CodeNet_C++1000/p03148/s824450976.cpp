#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    vector<P> v;
    for (int i = 0; i < N; i++) {
        int t, d; cin >> t >> d; t--;
        v.push_back(P(t, d));
    }
    sort(v.begin(), v.end(), [](P p1, P p2) {
        return p1.second > p2.second;
    });

    ll res = 0;
    ll x = 0;
    vector<bool> check(N);
    priority_queue<int, vector<int>, greater<int>> que1;
    for (int i = 0; i < K; i++) {
        int& t = v[i].first;
        int& d = v[i].second;
        res += d;
        if (!check[t]) {
            x++;
            check[t] = true;
        }
        else que1.push(d);
    }
    ll ans = res + x * x;

    priority_queue<int> que2;
    for (int i = K; i < N; i++) {
        int& t = v[i].first;
        int& d = v[i].second;
        if (!check[t]) {
            que2.push(d);
            check[t] = true;
        }
    }

    while (!que1.empty() && !que2.empty()) {
        res -= que1.top(); que1.pop();
        res += que2.top(); que2.pop();
        x++;
        ans = max(ans, res + x * x);
    }

    cout << ans << "\n";
}