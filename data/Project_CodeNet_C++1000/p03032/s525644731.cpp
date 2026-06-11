#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N, K;
    cin >> N >> K;
    vec<int> V(N);
    rep(i, N) cin >> V[i];

    int ans = 0;
    rep(l, N + 1) rep(r, N + 1) {
        if (l + r > N || l + r > K) continue;
        vec<int> J;
        rep(i, l) J.push_back(V[i]);
        rep(i, r) J.push_back(V[N - 1 - i]);
        sort(all(J));
        int tmpans = accumulate(all(J), 0);
        int k      = min(K - (l + r), (int)J.size());
        rep(i, k) if (J[i] < 0) tmpans -= J[i];
        ans = max(ans, tmpans);
    }
    cout << ans << endl;
}