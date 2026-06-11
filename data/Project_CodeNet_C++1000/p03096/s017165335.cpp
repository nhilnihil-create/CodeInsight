#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }

ll dp[200010], sum[200010];

vector<pair<int, int>> runLengthEncoding(vector<int> s) {
    int n = s.size();
    vector<pair<int, int>> res;
    int pre = s[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (pre != s[i]) {
            res.pb({pre, cnt});
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }
    res.pb({pre, cnt});
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int NN; cin >> NN;
    vector<int> CC(NN);
    rep(i, NN) cin >> CC[i];

    vector<P> C = runLengthEncoding(CC);
    int N = C.size();

    dp[0] = 1;
    rep(i, N) {
        int c = C[i].fi;
        dp[i+1] += sum[c] + dp[i];
        dp[i+1] %= mod;
        sum[c] = dp[i+1];
        sum[c] % mod;
    }

    cout << dp[N] % mod << endl;
}