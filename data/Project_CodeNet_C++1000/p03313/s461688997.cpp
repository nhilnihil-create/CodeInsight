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

plli maxes[300100];
lli arr[300100];

void insert_plli(plli &v, lli vv) {
    if (v.first == vv || v.second == vv) return;
    if (v.first < vv) {
        v.second = v.first;
        v.first = vv;
    } else if (v.second < vv) {
        v.second = vv;
    }
}

void insert_plli(plli &v, plli vv) {
    insert_plli(v, vv.first);
    insert_plli(v, vv.second);
}

int main() {
    int n;
    scanf("%d", &n);
    int N = 1 << n, i, j;
    for (i=0; i<N; ++i) {
        scanf("%lld", arr+i);
        arr[i] = (arr[i] << n) | i;
    }
    maxes[0] = plli(arr[0], 0);
    for (i=0; i<N; ++i) {
        for (j=0; j<n; ++j) {
            if (i & (1 << j)) {
                insert_plli(maxes[i], maxes[i & ~(1 << j)]);
            }
        }
        insert_plli(maxes[i], arr[i]);
    }
    lli now_v = 0;
    for (i=1; i<N; ++i) {
        printf("%lld\n", now_v = max(now_v, (maxes[i].first >> n) + (maxes[i].second >> n)));
    }
    return 0;
}
