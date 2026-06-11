#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

int n;

string s;

const int MAXN = 200005;
int a[MAXN], m[MAXN];

int dp[(1 << 26) + 5];

int mask(int x) {
    return 1 << x;
}

bool contains(int s, int x) {
    return s & mask(x);
}

int main() {
    cin >> s;

    n = s.size();

    FORN(i, n) {
        a[i + 1] = s[i] - 'a';
    }

    m[0] = 0;

    FOR1(i, n) {
        m[i] = m[i-1] ^ mask(a[i]);
    }

    fill(dp, dp + (1 << 26) + 5, INF);

    dp[m[n]] = 0;

    FORD(i, n) {
        int best = INF;

        FORN(j, 26) {
            best = min(best, 1 + dp[m[i] ^ mask(j)]);
        }

        dp[m[i]] = min(dp[m[i]], best);

//        DEBUG(m[i]);
//        DEBUG(dp[m[i]]);
    }

    cout << max(1, dp[0]) << "\n";

    return 0;
}