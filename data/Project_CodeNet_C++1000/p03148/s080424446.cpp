#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ll n, k, t, d;
    vector<pair<ll, ll>> s;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t >> d;
        s.emplace_back(d, t);
    }
    sort(s.begin(), s.end(), greater<>());
    ll sum = 0, typ = 0;
    map<ll, multiset<ll>> u;
    priority_queue<pair<ll, ll>> q;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(greater<>())> p((greater<>()),
                                                                                vector<pair<ll, ll>>());
    for (int i = 0; i < k; i++) u[s[i].second].insert(s[i].first);
    for (auto &e:u) typ++;
    for (auto &e:u) for (auto f:e.second) sum += f;
    for (int i = 0; i < k; i++) p.push(s[i]);
    for (int i = k; i < n; i++) q.push(s[i]);
    ll res = sum + typ * typ;

    while (1) {
        while ((!p.empty()) && u[p.top().second].size() <= 1) p.pop();
        while ((!q.empty()) && u[q.top().second].size() > 0) q.pop();
        if (p.empty() || q.empty()) break;
        u[q.top().second].insert(q.top().first);
        u[p.top().second].erase(u[p.top().second].find(p.top().first));
        sum += (q.top().first - p.top().first);
        typ++;
        res = max((long long) (sum + typ * typ), res);
        p.pop();
        q.pop();
    }
    cout << res << endl;
    return 0;
}
