#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n;
llong ans = 0;

int main() {
    cin >> n;

    llong ans = 0;
    // km + k = k(m + 1)
    for (llong i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            llong d = i - 1;

            if (d != 0 && n / d == n % d) {
                ans += d;
            }

            d = n / i - 1;
            if (d != 0 && n / d == n % d) {
                ans += d;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
