#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    vector<ll> sum(N + 1, 0);
    rep(i, N) sum[i + 1] = sum[i] + A[i];
    vector<ll> S;
    for (int l = 0; l < N; ++l) {
        for (int r = l + 1; r <= N; ++r) {
            S.push_back(sum[r] - sum[l]);
        }
    }
    
    ll ans = 0;
    for (int i = 60; i >= 0; --i) {
        int cnt = 0;
        for (auto s : S) {
            if ((s >> i) & 1) ++cnt;
        }
        if (cnt < K) continue;
        ans += (1LL << i);
        vector<ll> T;
        for (auto s : S) {
            if ((s >> i) & 1) T.push_back(s);
        }
        swap(S, T);
    }
    cout << ans << "\n";
    return 0;
}
