#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    vector<ll> alt;
    for (int i=0; i<n; i++) {
        ll cur = 0;
        for (int j=i; j<n; j++) {
            cur += a.at(j);
            alt.push_back(cur);
        }
    }
    sort(alt.begin(), alt.end(), greater<ll>());
    ll res = 0;
    for (int i=50; i>=0; i--) {
        int cnt = count_if(alt.begin(), alt.end(), [i, res](ll a){ return (a & (res + (1LL << i))) == (res + (1LL << i));});
        if (cnt >= k) {
            res += (1LL << i);
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
