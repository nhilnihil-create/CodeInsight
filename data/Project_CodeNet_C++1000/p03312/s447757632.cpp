#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> acc(N + 1);
    for (int i = 0; i < N; i++) {
        acc[i + 1] = acc[i] + A[i];
    }


    ll ans = 1LL << 60;
    for(int j = 1; j < N; j++) {
        int i1 = lower_bound(all(acc), acc[j] / 2) - acc.begin();
        int k1 = lower_bound(all(acc), acc[j] + (acc[N] - acc[j]) / 2) - acc.begin();

        vector<int> I = {i1};
        vector<int> K = {k1};

        if (i1 - 1 >= 0) {
            I.push_back(i1 - 1);
        }
        if (k1 - 1 > j) {
            K.push_back(k1 - 1);
        }

        for(int u = 0; u < I.size(); u++) {
            for(int v = 0; v < K.size(); v++) {
                int i = I[u], k = K[v];
                vector<ll> area = {
                    acc[i],
                    acc[j] - acc[i],
                    acc[k] - acc[j],
                    acc[N] - acc[k]
                };
                sort(all(area));
                ans = min(ans, area.back() - area[0]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    #ifdef LOCAL_ENV
    cin.exceptions(ios::failbit);
    #endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    
    solve();
}