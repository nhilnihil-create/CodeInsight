#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];
    sort(h.begin(), h.end());
    ll res = INF;
    for (int i = 0; i+K-1 < N; ++i) {
        res = min(h[i+K-1]-h[i], res);
    }
    cout << res << endl;
    return 0;
}