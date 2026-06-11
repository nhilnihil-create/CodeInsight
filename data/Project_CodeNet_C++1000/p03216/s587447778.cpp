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
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

int N, Q;
string S;

ll solve(int k) {
    ll d = 0, c = 0, dc = 0;
    ll ans = 0;

    REP (i, N) {
        if (S[i] == 'D') {
            d++;
        } else if (S[i] == 'M') {
            c++;
            dc += d;
        } else if (S[i] == 'C') {
            ans += dc;
        }

        int j = i - k + 1;
        if (j < 0) continue;
        if (S[j] == 'D') {
            d--;
            dc -= c;
        } else if (S[j] == 'M') {
            c--;
        }
    }

    return ans;
}

int main() {
    cin >> N >> S >> Q;
    int k;
    REP (q, Q) {
        cin >> k;
        cout << solve(k) << "\n";
    }
}