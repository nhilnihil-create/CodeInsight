#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i=0; i<N; ++i) cin >> s[i];

    vector<ll> cnt(5);
    for (string S : s) {
        if (S.front() == 'M') cnt[0]++;
        else if (S.front() == 'A') cnt[1]++;
        else if (S.front() == 'R') cnt[2]++;
        else if (S.front() == 'C') cnt[3]++;
        else if (S.front() == 'H') cnt[4]++;
    }
    ll ans = 0;
    for (int i=0; i<5; ++i) {
        for (int j=i+1; j<5; ++j) {
            for (int k=j+1; k<5; ++k) {
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
