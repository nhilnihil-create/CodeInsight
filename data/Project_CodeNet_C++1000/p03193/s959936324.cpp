#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, H, W;
vector<ll> A, B;
int main() {
    cin >> N >> H >> W;
    A.resize(N); B.reserve(N);
    rep(i, N) cin >> A[i] >> B[i];

    ll ans = 0;
    rep(i, N) {
        if (A[i] < H) continue;
        if (B[i] < W) continue;
        ans++;
    }
    cout << ans << endl;
}