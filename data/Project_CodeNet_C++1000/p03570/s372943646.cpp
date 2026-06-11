#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 2e5+10;
const int INF = 1e7;

string S;
int dp[1<<26];

ll solve() {
    REP (i, 1<<26) dp[i] = INF;

    int h = 0;
    REP (i, S.size()) {
        h ^= 1<<(S[i]-'a');
        if (__builtin_popcount(h) <= 1) {
            dp[h] = 1;
            continue;
        }
        dp[h]++;
        REP (j, 26) CHMIN(dp[h], dp[h^(1<<j)]+1);
    }
    return dp[h];
}

int main() {
    cin >> S;
    cout << solve() << endl;
}