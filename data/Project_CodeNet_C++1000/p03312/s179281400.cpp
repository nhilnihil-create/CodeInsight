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
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;}

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

    ll ans = 1LL << 62;
    for (int b = 0; b <= N; b++) {
        int a1 = lower_bound(all(acc), acc[b] / 2) - acc.begin();
        int c1 = lower_bound(all(acc), (acc[N] - acc[b]) / 2 + acc[b]) - acc.begin();
        int a2 = a1 - 1;
        int c2 = c1 - 1;
        vector<ll> I1 = {a1}, I2 = {c1};
        if (a2 >= 0) I1.push_back(a2);
        if (c2 >= 0) I2.push_back(c2); 
        for (int i1 = 0; i1 < I1.size(); i1++) {
            for (int i2 = 0; i2 < I2.size(); i2++) {
                int a = I1[i1];
                int c = I2[i2];
                vector<ll> S = {acc[N] - acc[c], acc[c] - acc[b], acc[b] - acc[a], acc[a]};
                sort(all(S));
                ans = min(ans, abs(S[0] - S.back()));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}