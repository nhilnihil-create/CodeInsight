#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pll> AB(N);
    for (int i = 0; i < N; ++i) cin >> AB[i].first >> AB[i].second;
    sort(AB.begin(), AB.end());
    ll res = 0;
    for (int i = 0; i < N && M > 0; ++i) {
        res += AB[i].first * min(M, AB[i].second);
        M-=min(M, AB[i].second);
    }
    cout << res << endl;
    return 0;
}