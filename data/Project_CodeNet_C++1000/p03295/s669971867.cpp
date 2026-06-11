#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, M;
vector<P> v;
int main() {
    cin >> N >> M;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        v.push_back(P(b, a));
    }

    sort(v.begin(), v.end());

    // first: right
    // second: left

    // 重なる辺
    ll ans = 1;
    ll pos = v[0].first;

    for (int i = 1; i < M; i++) {
        // cout << v[i].second + 1 << " " << v[i].first + 1 << endl;
        if (v[i].second < pos) {
            continue;
        }

        pos = v[i].first; 
        ans++;
    }

    cout << ans << endl;
}