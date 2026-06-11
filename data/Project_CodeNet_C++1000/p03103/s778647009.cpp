#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;


int main() {
    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> shop(N);
    for(ll i=0; i<N; i++) {
        ll a, b;
        cin >> a >> b;
        shop.push_back(make_pair(a, b));
    }
    sort(shop.begin(), shop.end());

    ll count = 0;
    ll cost = 0;

    for(auto s : shop) {
        if(count + s.second >= M) {
            cost += (M-count) * s.first;
            cout << cost << endl;
            return 0;
        }
        else {
            cost += s.second * s.first;
            count += s.second;
        }
    }
}