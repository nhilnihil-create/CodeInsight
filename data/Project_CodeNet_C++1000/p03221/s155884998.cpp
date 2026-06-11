#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    vector<pair<ll, ll>> P;
    vector<vector<ll>> years;
    ll N, M;
    cin >> N >> M;
    years.resize(N);
    for(ll i = 0;i < M;i++) {
        ll p, y;
        cin >> p >> y;
        p--;
        P.emplace_back(p, y);
        years[p].push_back(y);
    }
    for(auto &i: years) sort(i.begin(), i.end());
    for(auto &i: P) {
        ll di = distance(years[i.first].begin(), lower_bound(years[i.first].begin(), years[i.first].end(), i.second));
        cout << setfill('0') << setw(6) << i.first + 1 << setfill('0') << setw(6) << di + 1 << endl;
    }
    return 0;
}
