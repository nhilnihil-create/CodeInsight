// failed to generate code

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P>> vec;
// vector<vector<int>> data(3, vector<int>(4));

ll N;
vector<vector<ll>> a(16, vector<ll>(16));
vector<ll> dp(1LL << 16, -1);
vector<ll> init(1LL << 16, 0);

ll rec(ll b) {
    if (dp[b] != -1) return dp[b];
    ll res = init[b];
    for (ll i = (b - 1) & b; i > 0; i = (i - 1) & b) {
        res = max(res, rec(i) + rec(b ^ i));
    }

    return dp[b] = res;
}

int main() {
    cin >> N;
    rep(i, N) rep(j, N) cin >> a[i][j];

    rep(i, 1LL << N) {
        rep(j, N) rep(k, N) if (((i >> j) & 1) && ((i >> k) & 1)) init[i] +=
            a[j][k];
        init[i] /= 2;
    }

    cout << rec((1LL << N) - 1) << endl;
}
