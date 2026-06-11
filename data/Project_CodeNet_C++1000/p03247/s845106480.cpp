#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;

ll N;
vector<pair<ll, ll>> xy;

void input() {
    cin >> N;
    xy.resize(N);
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }
}

void solve() {
    vector<ll> parities;
    set<ll> pset;
    for (auto pair : xy) {
        auto p = abs(pair.first + pair.second) % 2;
        parities.push_back(p);
        pset.insert(p);
    }
    if (pset.size() != 1) {
        cout << -1 << endl;
        return;
    }
    const ll MAXU = 31;
    vector<ll> arms;
    if (pset.find(0) != pset.end()) {
        arms.push_back(1);
    }
    for (ll i = 0; i <= MAXU; i++) {
        arms.push_back(1ull << i);
    }
    
    auto M = arms.size() - (parities[0] == 0 ? 1 : 0);
    cout << arms.size() << endl;
    for (auto arm : arms) {
        cout << arm << ' ';
    }
    cout << endl;
    
    for (ll i = 0; i < N; i++) {
        string dirs;
        string dir_type = "LDUR";
        auto x = xy[i].first, y = xy[i].second;
        if (parities[i] == 0) {
            x--;
            dirs.push_back('R');
        }
        auto u = ((x + y) >> 1) + (1ull << MAXU);
        auto v = ((x - y) >> 1) + (1ull << MAXU);
        for (ll r = 0; r < M; r++) {
            dirs.push_back(dir_type[(u>>r & 1)*2 + (v>>r & 1)]);
        }
        
        cout << dirs << endl;
    }
}


int main() {
    input();
//    cout << solve() << endl;
    solve();
    
    return 0;
}

