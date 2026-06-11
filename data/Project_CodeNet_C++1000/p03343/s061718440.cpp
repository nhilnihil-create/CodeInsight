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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for (int i=0; i<N; ++i) cin >> A[i];

    int res = INF;
    for (int mini : A) {
        vector<int> pos, tmp;
        for (int i=0; i<N; ++i) {
            if (A[i] < mini || i == N-1) {
                if (A[i] >= mini)
                    tmp.push_back(A[i]);
                sort(tmp.begin(), tmp.end());
                int len = (int)tmp.size();
                for (int i=0; i<len-K+1; ++i)
                    pos.push_back(tmp[i]);
                tmp.clear();
            } else {
                tmp.push_back(A[i]);
            }
        }
        if ((int)pos.size() < Q)
            continue;
        sort(pos.begin(), pos.end());
        chmin(res, pos[Q-1] - pos[0]);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
