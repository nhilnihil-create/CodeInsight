#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> h;
int main() {
    cin >> N;
    h.resize(N + 1);
    rep(i, N) cin >> h[i + 1];

    ll ans = 0;
    h[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (h[i - 1] < h[i]) {
            ans += (h[i] - h[i - 1]);
        }
    }

    cout << ans << endl;
}