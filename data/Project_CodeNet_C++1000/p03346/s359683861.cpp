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
#include <map>
#include <cmath>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
constexpr ll mod = 1000000007;

#define bs(n) (1ull<<(ull)(n))
#define rep(i, n) for(ll (i) = 0;(i) < (n);(i)++)

int main() {
    int n, p[300000];
    cin >> n;
    rep(i, n)cin >> p[i];
    rep(i, n)p[i]--;
    int q[300000];
    rep(i, n) q[p[i]] = i;
    int r = 0, f = 1000000, c = 0;
    rep(i, n) {
        if (f < q[i]) {
            c++;
        } else {
            c = 1;
        }
        f = q[i];
        r = max(r, c);
    }
    cout << n - r << endl;
}
