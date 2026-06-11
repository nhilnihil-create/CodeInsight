#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, M;
vector<ll> x;
int main() {
    cin >> N >> M;
    x.resize(M);
    rep(i, M) cin >> x[i];
    sort(x.begin(), x.end());

    vector<ll> dist;
    for (int i = 1; i < M; i++) {
        ll d = abs(x[i] - x[i - 1]);
        dist.push_back(d);
    }
    sort(dist.rbegin(), dist.rend());

    // N 個の区間を選ぶ
    // cout << min(N - 1, (ll)dist.size()) << endl;
    ll removed_cnt = N - 1;
    ll total = accumulate(dist.begin(), dist.end(), 0LL);

    for (int i = 0; i < removed_cnt; i++) {
        // if (dist.size() - 1 < i) break;
        // cout << dist[i] << " ";
        if ((int)dist.size() - 1 >= i) {
            total -= dist[i];
        }
    }
    cout << total << endl;
}