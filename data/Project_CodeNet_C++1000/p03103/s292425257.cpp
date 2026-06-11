#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
//#define int long long    ←保留
#define rep(i, n) for (int i = 0; i < n; i++)
const int MOD = 1e9 + 7;
const int INF = 1e18 + 9;
constexpr long double pi = 3.141592653589793238462643383279; //円周率
//C++(GCC9.2.1)

/*signed*/int main() {
    //宣言
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> vec(n);
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        vec[i] = make_pair(a, b);
    }
    sort(vec.begin(), vec.end());
    long long ans = 0;
    long long i = 0;
    while (m > 0) {
        long long buy = min(m, vec[i].second);
        ans += vec[i].first * buy;
        m -= buy;
        ++i;
    }
    cout << ans << endl;
    return 0;
}
