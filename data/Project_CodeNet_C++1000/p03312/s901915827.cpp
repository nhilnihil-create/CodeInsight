#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <map>
#include <sstream>
#include <bitset>
#include <random>
#include <tuple>
#include <array>
#include <tgmath.h>
#include <functional>
#include <climits>
#include <complex>
#include <unistd.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

typedef tuple<lli, lli, lli, lli> tl4;

lli arr[200100], psum[200100];

tl4 find_midway(lli *arr, int cnt, lli *psum) {
    //printf("call: %d %lld\n", cnt, *psum);
    lli v = psum[0] + (psum[cnt] - psum[0]) / 2;
    int idx_where = (int)(upper_bound(psum, psum+cnt+1, v) - psum);
    lli a, b, c, d;
    if (idx_where) {
        tie(a, b, c, d) = tl4(
            psum[idx_where] - psum[0], psum[cnt] - psum[idx_where],
            psum[idx_where - 1] - psum[0], psum[cnt] - psum[idx_where - 1]
        );
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        //printf("%lld %lld %lld %lld\n", a, c, b, d);
        return tl4(a, c, b, d);
    }
    tie(a, b) = plli(psum[idx_where] - psum[0], psum[cnt] - psum[idx_where]);
    if (a > b) swap(a, b);
    //printf("= %lld %lld %lld %lld\n", a, a, b, b);
    return tl4(a, a, b, b);
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    for (i=1; i<=n; ++i) {
        scanf("%lld", arr+i);
        psum[i] = psum[i-1] + arr[i];
    }
    lli diff = 1e18;
    lli a, b, c, d, e, f, g, h;
    for (i=2; i<=n-2; ++i) {
        tie(a, b, c, d) = find_midway(arr, i, psum);
        tie(e, f, g, h) = find_midway(arr+i, n-i, psum+i);
        diff = min({
            diff,
            max(c, g) - min(a, e),
            max(d, g) - min(b, e),
            max(c, h) - min(a, f),
            max(d, h) - min(b, f)
        });
    }
    printf("%lld\n", diff);
    return 0;
}
