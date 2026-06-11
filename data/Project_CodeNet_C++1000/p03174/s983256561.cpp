#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll dp[1<<21] = {};

int main() {
    nfs
    int i, j, mask, n, bit;
    cin >> n;
    dp[0] = 1;
    for (i = 0; i < n; i++) {
        
        // cout << i << endl;
        int coolMask = 0;
        for (j = 0; j < n; j++) {
            cin >> bit;
            coolMask ^= bit ? 1<<j : 0;
        }
        
        for (mask = 0; mask < (1<<n); mask++) {
            // cout << mask << ',' << endl;
            if (__builtin_popcount(mask) == i + 1) {
                int checkMask = mask & coolMask;
                while (checkMask) {
                    int lastPos = checkMask & (-checkMask);
                    dp[mask] = (dp[mask] + dp[mask^lastPos]) % mod;
                    checkMask ^= lastPos;
                }
            }
        }
    }
    cout << dp[(1<<n) - 1];
}