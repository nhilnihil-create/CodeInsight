#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s;
    int k;

    cin >> s >> k;

    int n = (int)s.size();

    vec< vec< vec< int > > > dp(n, vec< vec< int > >(n, vec< int >(k + 1, 0)));

    for(int l = n - 1;l >= 0;l--) {
        for(int r = l;r < n;r++) {
            if(l == r) {
                for(int q = 0;q <= k;q++) {
                    dp[l][r][q] = 1;
                }
                continue;
            }
            for(int q = 0;q <= k;q++) {
                dp[l][r][q] = max(dp[l + 1][r][q], dp[l][r - 1][q]);
                if(q) dp[l][r][q] = max(dp[l][r][q], dp[l][r][q - 1]);
                int add = !(s[l] == s[r]);
                if(q >= add) {
                    dp[l][r][q] = max(dp[l][r][q], dp[l + 1][r - 1][q - add] + 2);
                }
            }
        }
    }

    cout << dp[0][n - 1][k] << "\n";

    return 0;
}
