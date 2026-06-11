#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < N && cnt < M; i++) {
        int m = min(M - cnt, v[i].second);
        cnt += m;
        ans += (ll)m * v[i].first;
    }
    cout << ans << endl;
}