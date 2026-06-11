#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int n, t;

int min_cost(vector<pair<int, int>> &r) {
    sort(r.begin(), r.end());
    for (auto p : r) {
        if (p.second <= t) {
            return p.first;
        }
    }

    return -1;
}

int main() {
    cin >> n >> t;
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; i++) {
        int cost, time; cin >> cost >> time;
        r[i] = make_pair(cost, time);
    }
    
    int ans = min_cost(r);
    if (ans == -1) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}