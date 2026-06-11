#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll INF = 1LL << 62;
constexpr ll MOD = 1e9 + 7;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    vector<ll> C(26, 0);
    for (auto s : S) {
        C[s - 'a']++;
    }

    ll spicies = 0;
    for (auto c : C) {
        if (c) {
            spicies++;
        }
    }

    ll h[2] = {-1, -1};
    for (ll len = 0; len < S.size(); len++) {
        ll ma = 0;
        ll idx = -1;
        for (ll i = 0; i < 26; i++) {
            if (C[i] > ma && i != h[0] && i != h[1]) {
                ma = C[i];
                idx = i;
            }
        }

        if (idx == -1) {
            cout << "NO" << endl;
            return 0;
        }

        C[idx]--;
        h[0] = h[1];
        h[1] = idx;
    }

    cout << "YES" << endl;
    return 0;
}

