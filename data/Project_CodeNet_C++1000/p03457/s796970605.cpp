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
    long long n;
    cin >> n;
    long long x, y;
    x = y = 0;
    long long c;
    c = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (abs(x - a) + abs(y - b) > t - c) {
            flag = false;
        }
        else if (abs(x - a) + abs(y - b) < t - c) {
            if ((abs(x - a) + abs(y - b)) % 2 != 0) {
                if (t - c % 2 == 0) flag = false;
            }
            else {
                if (t - c % 2 != 0) flag = false;
            }
        }
        x = a;
        y = b;
        c = t;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}