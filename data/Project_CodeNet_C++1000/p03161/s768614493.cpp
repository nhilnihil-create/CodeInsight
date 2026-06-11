#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define NL endl
#define pi 2.0*acos(0.0)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k, arr[100005], dp[100005];

ll calculateJump(ll pos) {
    if(pos >= n) return 0;
    if (dp[pos] != -1) return dp[pos];
    ll minm = abs(arr[pos] - arr[pos + 1]) + calculateJump(pos + 1);
    for (ll i = 2; i <= k; i++) {
        if (i + pos <= n) minm = min(minm, abs(arr[pos] - arr[pos + i]) + calculateJump(pos + i));
    }
    dp[pos] = minm;
    return dp[pos];
}

int main() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    fill(dp, dp + n + 1, -1);
    cout << calculateJump(1) << endl;
}
