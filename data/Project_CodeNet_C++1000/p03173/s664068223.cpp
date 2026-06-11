#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
const int64_t INF = 1e18;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    using P = pair<int64_t, int64_t>;
    vector<vector<P>> dp(N + 1, vector<P>(N + 1));
    auto f = [&](auto &&f, int l, int r) -> P {
        if(dp[l][r] != P(0LL, 0LL)) return dp[l][r];
        if(l + 1 == r) return make_pair(0, A[l]);
        P res = make_pair(INF, INF);
        for(int i = l + 1; i < r; ++i) {
            auto left = f(f, l, i);
            auto right = f(f, i, r);
            auto cost = left.first + right.first;
            auto sz = left.second + right.second;
            if(res.first > cost + sz) {
                res.first = cost + sz;
                res.second = sz;
            }
        }
        return dp[l][r] = res;
    };
    cout << f(f, 0, N).first << '\n';
}
