#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, K;
    cin >> N >> K;

    vec<ll> x(N), y(N),xs(N),ys(N);
    rep(i, N) cin >> x[i] >> y[i];
    xs = x;
    ys = y;
    sort(all(xs));
    sort(all(ys));

    ll ans = (1LL << 62);
    rep(i, N - 1) for (int j = i + 1; j < N; ++j)
        rep(k, N - 1) for (int l = k + 1; l < N; ++l) {
        ll xmin = xs[i], xmax = xs[j], ymin = ys[k], ymax = ys[l];
        
        int cnt = 0;
        rep(p,N){
            if(xmin <= x[p] && x[p] <= xmax && ymin <= y[p] && y[p] <= ymax) ++cnt;
        }
        if(cnt >= K) ans = min(ans,1LL*(xmax-xmin)*(ymax-ymin));
    }

    cout << ans << endl;
}
