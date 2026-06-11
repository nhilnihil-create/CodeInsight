#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define Rep(i, n) for( int i = 0; i < (n); i++ )
#define Rrep(i, a, n) for( int i = (a); i < (n); i++ )
#define All(v) v.begin(), v.end()

typedef pair<int, int> Pii;
typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;

int dp[1 << 26];

signed main() {
    string s;
    int n, bit = 0;

    cin >> s;
    n = s.size();

    fill_n(dp, 1 << 26, INF);
    dp[0] = 0;
    Rep(i, n) {
        bit ^= 1 << (s[i] - 'a');
        Rep(j, 26) {
            dp[bit] = min(dp[bit], dp[bit ^ (1 << j)] + 1);
        }
    }

    cout << max(1, dp[bit]) << endl;
    return 0;
}
