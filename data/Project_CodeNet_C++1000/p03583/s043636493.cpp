#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

signed main() {
    int N;

    cin >> N;

    FORE(A, 1, 3500) {
        FORE(B, 1, 3500) {
            int n = N * A * B;
            int d = 4 * A * B - A * N - B * N;

            if (d > 0 && n % d == 0 && n < 3500 * d) {
                int ans = n / d;
                cout << A << " " << B << " " << ans << endl;
                return 0;
            }
        }
    }

}
