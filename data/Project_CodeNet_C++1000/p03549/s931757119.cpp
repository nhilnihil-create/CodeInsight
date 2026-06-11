// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;
using llong = long long;

// library section
// ===

llong n, m;

int main() {
    cin >> n >> m;

    llong t = 1900 * m + 100 * (n - m);

    printf("%lld\n", t * (1 << m));

    return 0;
};

