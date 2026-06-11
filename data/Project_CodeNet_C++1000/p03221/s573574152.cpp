// 7/4
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M), R(M);
    rep(i, M) cin >> P[i] >> Y[i];

    vector<pair<int, int>> L(M);
    rep(i, M) {
        L[i] = pair<int, int>(Y[i], i);
    }
    sort(L.begin(), L.end());
    map<int, int> mp;

    rep(i, M) {
        // R[i] = mp[P[i]];
        // mp[P[i]]++;
        int id = L[i].second;
        R[id] = mp[P[id]];
        mp[P[id]]++;
    }

    rep(i, M) {
        cout << std::setfill('0') << std::right << std::setw(6) << P[i] << std::setfill('0') << std::right << std::setw(6) << R[i]+1 << endl;
    }
}