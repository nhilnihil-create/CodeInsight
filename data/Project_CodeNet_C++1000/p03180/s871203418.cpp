#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 17;

const int inf = 1e15;

int n, a[N][N], dp[(1 << N)], sum[(1 << N)];

bool checkBit(int x, int pos) {
    if((x & (1 << pos)))
        return 1;
    else
        return 0;
}

int setBit(int x, int pos) {
    return (x | (1 << pos));
}

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for(int mask = 0; mask < (1 << N); mask++)
        dp[mask] = -inf;
    for(int mask = 0; mask < (1 << n); mask++) {
        int people = 0, total = 0;
        for(int j = 0; j < n; j++) {
            if(checkBit(mask, j) == 0) {
                total = 0;
                for(int k = 0; k < n; k++) {
                    if(checkBit(mask, k))
                        total += a[k][j];
                }
                sum[setBit(mask, j)] = total + sum[mask];
            }
        }
        //cout << sum[mask] << " " << mask << "\n";
    }
    dp[0] = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = sum[mask];
        for(int submask = mask; submask; submask = (submask - 1) & mask)
            dp[mask] = max(dp[mask], dp[submask] + sum[mask ^ submask]);
    }
    cout << dp[(1 << n) - 1];
}
