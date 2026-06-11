#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <time.h>
#include <stdlib.h>
#include <bitset>
#include <algorithm>

#include <chrono>

#define INF 1e9
#define LL_INF 1e18

#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)(x.size()))

#define MOD1 998244353
#define MOD2 666013
#define P1 255
#define P2 2059

using namespace std;

typedef long long int ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define nmax (1 << 17) + 5
#define MOD (int)((1e9) + 7)

int n;
ll val[nmax]; // mask (value if we choose to have these rabits in the same group)
ll dp[nmax]; // dp[mask] , mask already grouped rabits
int a[20][20];

bool fr[nmax];

ll back(int mask)
{
    if (fr[mask]) return dp[mask];

    fr[mask] = true;

    vector <int> vc;

    for (int i = 0; i < n; i++)
        if (((mask >> i) & 1)) vc.pb(i);

    int nn = SZ(vc);

    // remove some bits
    for (int i = 0; i < (1 << nn); i++)
    {
        int c_mask = 0;

        for (int j = 0; j < nn; j++)
            if ((i >> j) & 1) c_mask |= (1 << vc[j]);

        // remove c_mask from mask

        dp[mask] = max(dp[mask], back(c_mask) + val[mask ^ c_mask]);
    }

    return dp[mask];
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < (1 << n); i++) {

        ll sum = 0;

        vector <int> vc;

        for (int j = 0; j < n; j++)
            if (((i >> j) & 1) == 1) vc.pb(j + 1);

        for (int j = 0; j < SZ(vc); j++)
            for (int k = j + 1; k < SZ(vc); k++)
                sum = sum + a[vc[j]][vc[k]];

        val[i] = sum;
    }

    fr[0] = true;

    printf("%lld", back((1 << n) - 1));

    // IMPORTANT!!!!!
    // Are you missing something????
    // check limits, int or ll

    return 0;
}