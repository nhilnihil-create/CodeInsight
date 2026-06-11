#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main() {
    int N, K;
    cin >> N >> K;

    vector<int> As(N);
    REP(i, N) {
        cin >> As.at(i);
    }

    int ans = INF;

    REP(l, N) {
        int r = l + K - 1;
        if (r >= N) {
            continue;
        }

        // debug(r);
        // debug(l);
        int l2r = abs(As.at(l)) + abs(As.at(r) - As.at(l));
        int r2l = abs(As.at(r)) + abs(As.at(l) - As.at(r));

        ans = min({ans, l2r, r2l});
    }

    cout << ans << endl;
}
