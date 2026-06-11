#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, bool>> G[100000];
ll K;
vector<ll> d(100000, LLONG_MAX);
priority_queue<pair<ll, int>> que;
int main () {
    cin >> K;
    for (int i = 0; i < K; i++) {
        G[i].push_back(make_pair((i+1)%K, 1));
        G[i].push_back(make_pair((i*10)%K, 0));
    }
    d[1] = 1;
    que.push(make_pair(-d[1], 1));
    while (que.size()) {
        auto x = que.top();
        que.pop();
        if (d[x.second] < -x.first) continue;
        for (auto t: G[x.second]) {
            if (d[t.first] > -x.first+t.second) {
                d[t.first] = -x.first+t.second;
                que.push(make_pair(-d[t.first], t.first));
            }
        }
    }
    cout << d[0] << endl;
}