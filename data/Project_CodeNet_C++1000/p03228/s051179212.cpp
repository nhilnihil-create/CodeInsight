#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

typedef long long ll;

const int INF = 1000000000;
const int MOD = 1000000007;

int main(int argc, char *argv[]) {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int A, B, K;
    cin >> A >> B >> K;

    rep(i, K) {
        if (i%2) {
            if (B%2) --B;
            A += B/2, B /= 2;
        } else {
            if (A%2) --A;
            B += A/2, A /= 2;
        }
    }
    cout << A << ' ' << B << endl;
    return 0;
}