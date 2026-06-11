#ifdef BUILT_LOCAL

#include "niklib.h"

#endif

#include <iostream>
#include <utility>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mod = 1000000007;

#define bs(n) (1ll<<(ll)(n))
#define rep(i, n) for(ll (i) = 0;(i) < (n);(i)++)
#define rrep(i, n) for(ll (i) = 1;(i) <= (n);(i)++)

ll N, Z, W;
ll *a;

ll dp[2][2000][2];

ll rec2(ll, ll);

ll rec(ll a, ll b) {
    if (dp[a][b][0] == 0) {
        dp[a][b][0] = 1;
        dp[a][b][1] = rec2(a, b);
    }
    return dp[a][b][1];
}

ll rec2(ll turnX, ll nRemoved) {
    ll nRemain = N - nRemoved;
    ll aOpponent = 0;
    if (nRemoved > 0) aOpponent = a[nRemoved - 1];
    else {
        if (turnX == 1) aOpponent = W;
        else aOpponent = Z;
    }
    if (turnX == 1) {
        ll maxScore = abs(aOpponent - a[N - 1]);
        for (ll i = 1; i < nRemain; i++) {
            maxScore = max(maxScore, rec(0, nRemoved + i));
        }
        return maxScore;
    } else {
        ll minScore = abs(aOpponent - a[N - 1]);
        for (ll i = 1; i < nRemain; i++) {
            minScore = min(minScore, rec(1, nRemoved + i));
        }
        return minScore;
    }
}

int main() {
    cin >> N >> Z >> W;
    a = new ll[N];
    for (ll i = 0; i < N; i++)cin >> a[i];
    cout << rec(1, 0) << endl;
}