#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    ull N, x;
    cin >> N >> x;
    vector<ull> X(N);
    vector<ull> accX(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        accX[i + 1] = accX[i] + X[i];
    }

    ull ans = numeric_limits<ull>::max();
    for(int k = 1; k <= N; k++) {
        int w = k * 2;
        ull cnt = 0;
        ull sum = 0;
        bool f = false;
        for(int t = N; ; t -= w) {
            if (f) w = k;
            ull cost = 5 + 2 * cnt;
            sum += cost * (accX[t] - accX[max(0, t - w)]);
            if (t - w <= 0) break;
            cnt++;
            f = true;
        }
        ans = min(ans, k * x + sum);
    }
    cout << ans + N * x << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}