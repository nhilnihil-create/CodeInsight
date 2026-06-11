#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) cin >> s[i];

    int res = 0, as = 0, bs = 0, ab = 0;

    rep(i, N) {
        int n = s[i].size();
        for (int j = 0; j < n-1; j++) {
            if (s[i][j] == 'A' && s[i][j+1] == 'B') res++;
        }
        if (s[i][0] == 'B' && s[i][n-1] != 'A') bs++;
        if (s[i][n-1] == 'A' && s[i][0] != 'B') as++;
        if (s[i][0] == 'B' && s[i][n-1] == 'A') ab++;
    }

    if (ab == 0) {
        res += min(as, bs);
    }
    else {
        if (as == 0 && bs == 0) {
            res += ab-1;
        }
        else {
            res += ab + min(as, bs);
        }
    }

    cout << res << endl;
    return 0;
}
