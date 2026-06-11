#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr double EPS = 1e-10;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;


int main() {
    ll N, A, B; cin >> N >> A >> B;
    vi p(N);
    rep(i, N) cin >> p[i];

    /*dp[i][j] := i 個まで見て、右にうごさないことを確定した最大の値が j である状態を実現する
    最小コスト LISのO(N^2)解放にちょっと類似*/
    vector<vll> dp(N + 1, vll(N + 1, INF));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, N + 1) {
            if (dp[i][j] == INF) continue;
            if (p[i] > j) {
                chmin(dp[i + 1][p[i]], dp[i][j]);
                chmin(dp[i + 1][j], dp[i][j] + A);
            }
            else {
                chmin(dp[i + 1][j], dp[i][j] + B);
            }
        }
    }

    ll ans = INF;
    rep(j, N + 1) chmin(ans, dp[N][j]);
    cout << ans << endl;
}