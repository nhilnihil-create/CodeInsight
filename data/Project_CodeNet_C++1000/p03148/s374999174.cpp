#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using P = pair<ll, int>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k, idx = 1;
    cin >> n >> k;
    vector<P> ts;
    map<int, int> mp;
    rep(i, 0, n) {
        int t;
        ll d;
        cin >> t >> d;
        if (mp[t] == 0) {
            mp[t] = idx;
            idx++;
        }
        ts.push_back(make_pair(-d, mp[t]));
    }
    sort(ts.begin(), ts.end());
    rep(i, 0, n) ts[i].first *= -1;

    set<int> used;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    priority_queue<ll> pqb;
    ll ans = 0;
    ll sum = 0;

    rep(i, 0, k) {
        if (used.find(ts[i].second) != used.end())
            pq.push(ts[i].first);
        sum += ts[i].first;
        used.insert(ts[i].second);
    }
    ll sz = used.size();

    rep(i, k, n) {
        if (used.find(ts[i].second) == used.end())
            pqb.push(ts[i].first);
        used.insert(ts[i].second);
    }

    ans = sum + sz * sz;
    while ((!pqb.empty()) && (!pq.empty())) {
        sz++;
        sum += pqb.top() - pq.top();

        pqb.pop();
        pq.pop();
        ans = max(ans, sum + sz * sz);
    }

    cout << ans << endl;
    return 0;
}