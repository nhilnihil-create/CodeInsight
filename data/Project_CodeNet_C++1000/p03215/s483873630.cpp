#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N), sum(N + 1), B, can;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum[i + 1] = A[i];
    }

    rep(i, N) { sum[i + 1] += sum[i]; }

    for (int i = 0; i < N + 1; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            B.push_back(sum[j] - sum[i]);
        }
    }

    sort(all(B));
    vector<ll> now = B;
    for (int i = 60; i > -1; i--) {
        vector<ll> next;
        for (auto n : now) {
            if (n & (1LL << i))
                next.push_back(n);
        }
        // 桁が大きいところにbitフラグが立っている順に、振るい落として候補を絞っていく。
        if (next.size() >= K)
            now = next;
    }

    ll ans = now[now.size() - 1];
    rep(i, K) { ans &= now[now.size() - 1 - i]; }

    cout << ans << endl;
}