
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define NL endl
#define pi 2.0*acos(0.0)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;

ll dp[3] = {0, 0, 0}, input[3];

int main() {
    ll n, a, b, c, maxm;
    cin >> n;
    cin >> dp[0] >> dp[1] >> dp[2];
    for (ll i = 0; i < n - 1; i++) {
        for (ll a = 0; a < 3; a++) cin >> input[a];
        for (ll k = 0; k < 3; k++) {
            maxm = -1;
            for (ll l = 0; l < 3; l++) {
                if (k != l) {
                    maxm = max(maxm, dp[l] + input[k]);
                }
            }
            input[k] = maxm;
        }
        for (ll b = 0; b < 3; b++) dp[b] = input[b];
    }
    cout << max(max(dp[0], dp[1]), dp[2]) << '\n';
}
