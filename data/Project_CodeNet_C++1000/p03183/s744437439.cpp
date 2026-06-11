#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
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
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;


int N, W[1010], S[1010], V[1010];
ll dp[1010][30101];
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N;
    rep(i, N) cin >> W[i] >> S[i] >> V[i];

    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int a, int b) { return min(S[a], S[b] - W[a]) > min(S[b], S[a] - W[b]); });

    rep(i, N) {
        rep(tot, 20101) {
            int a = ord[i];
            chmax(dp[i + 1][tot], dp[i][tot]);
            if (tot <= S[a]) chmax(dp[i + 1][tot + W[a]], dp[i][tot] + V[a]);
        }
    }

    ll ans = 0;
    rep(tot, 20101) chmax(ans, dp[N][tot]);
    cout << ans << endl;
}