#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <string.h>
#include <map>
#include <iomanip>
#include <time.h>
using namespace std;
typedef long long ll;
#define _ << " " <<

int main() {
    ll n, q;
    string s;
    cin >> n >> s >> q;

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;

        ll ans = 0, dp[3] = {0, 0, 0};
        ll sm[3] = {0, 0, 0};
        for (int j = 0; j < k; j++) {
            if (char(s[j]) == 'D') {
                dp[0]++;  sm[0]++;
            }
            if (char(s[j]) == 'M') {
                dp[1] += dp[0];  sm[1]++;
            }
            if (char(s[j]) == 'C') {
                dp[2] += dp[1];  sm[2]++;
            }
        }
        ans += dp[2];
        //cerr << sm[0] _ sm[1] _ sm[2] _ dp[0] _ dp[1] _ dp[2] _ ans << endl;

        for (int j = k; j < n; j++) {
            dp[2] = 0;
            if (char(s[j - k]) == 'D') {
                dp[0]--;  dp[1] -= sm[1];  sm[0]--;
            }
            if (char(s[j - k]) == 'M') {
                sm[1]--;
            }
            if (char(s[j - k]) == 'C') {
                sm[2]--;
            }

            if (char(s[j]) == 'D') {
                dp[0]++;  sm[0]++;
            }
            if (char(s[j]) == 'M') {
                dp[1] += dp[0];  sm[1]++;
            }
            if (char(s[j]) == 'C') {
                dp[2] = dp[1];  sm[2]++;
            }
            ans += dp[2];
            //cerr << sm[0] _ sm[1] _ sm[2] _ dp[0] _ dp[1] _ dp[2] _ ans << endl;
        }

        cout << ans << endl;
    }
}