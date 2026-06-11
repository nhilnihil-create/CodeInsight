#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define SORT(c) sort((c).begin(), (c).end())
#define RSORT(c) sort((c).rbegin(), (c).rend())
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1e+9 + 7;
// --------------------------------------------------------


const int MAX_N = 1e+5;
VI dp(MAX_N, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, K; cin >> N >> K;
    VI h(N); REP(i,N) cin >> h[i];

    FOR(i,1,N) {
        dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        FOR(j,2,K+1) {
            if (i-j < 0) continue;
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << dp[N-1] << '\n';

    return 0;
}
// https://atcoder.jp/contests/dp/tasks/dp_b
