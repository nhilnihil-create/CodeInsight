#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
void chmax(T &a, U b) {
    if (a < b) a = b;
}
template <class T, class U>
void chmin(T &a, U b) {
    if (b < a) a = b;
}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

void solve(long long N, std::vector<long long> w, std::vector<long long> s, std::vector<long long> v) {

    vector<pair<int, int>> vp;
    rep(i, N) vp.emplace_back(s[i] + w[i], i);
    sort(all(vp));

    vi dp(20010, 0);
    rep(i, N) {
        int idx = vp[i].second;
        for (int j = s[idx]; j >= 0; j--) {
            if (j + w[idx] <= 20000) {
                chmax(dp[j + w[idx]], dp[j] + v[idx]);
            }
        }
    }
    int ans = 0;
    rep(i, 20010) chmax(ans, dp[i]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    long long N;
    scanf("%lld", &N);
    std::vector<long long> w(N);
    std::vector<long long> s(N);
    std::vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &w[i]);
        scanf("%lld", &s[i]);
        scanf("%lld", &v[i]);
    }
    solve(N, std::move(w), std::move(s), std::move(v));
    return 0;
}
