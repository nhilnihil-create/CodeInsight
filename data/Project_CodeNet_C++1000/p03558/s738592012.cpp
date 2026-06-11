#include <bits/stdc++.h>

using namespace std;

#define ll long long
constexpr ll inf = 1e9+7;

int main() {
    ll K;
    cin>>K;

    vector<pair<ll, ll>> edges(K);
    for (ll k = 0; k < K; k++) {
        edges[k].first = (k+1)%K;
        edges[k].second = (k*10)%K;
    }

    // Dijkstra
    // priority_queue<(cost, to)>
    vector<ll> costs(K, inf);
    deque<pair<ll, ll>> q;
    q.push_front(make_pair(1, 1));
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        if (costs[p.second] < p.first) continue;
        costs[p.second] = p.first;
        if (p.second == 0) {
            cout<<p.first<<endl;
            return 0;
        }
        if (costs[edges[p.second].first] > p.first + 1)
            q.push_back(make_pair(p.first + 1, edges[p.second].first));
        if (costs[edges[p.second].second] > p.first)
            q.push_front(make_pair(p.first, edges[p.second].second));
    }
}