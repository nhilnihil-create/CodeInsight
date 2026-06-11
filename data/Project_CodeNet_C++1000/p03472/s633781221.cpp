#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll N, H;
    cin >> N >> H;

    vector<Pll> A(N), B(N);
    for (ll i = 0; i < N; i++) {
        ll ai, bi;
        cin >> ai >> bi;
        A[i] = make_pair(ai, i);
        B[i] = make_pair(bi, i);
    }

    sort(A.begin(), A.end(), greater<Pll>());
    sort(B.begin(), B.end(), greater<Pll>());

    ll ans = (H + A[0].first - 1) / A[0].first;

    ll b_sum = 0;
    for (ll i = 0; i < N; i++) {
        ll bi, b_idx;
        tie(bi, b_idx) = B[i];

        b_sum += bi;

        ll t = (H - b_sum + A[0].first - 1) / A[0].first;
        t = max(t, 0LL);

        ans = min(ans, t + i + 1);
    }

    cout << ans << endl;

    return 0;
}