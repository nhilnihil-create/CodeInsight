#include <algorithm>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

ll to5(ll a) { return a * a * a * a * a; }

int main() {
    ios::sync_with_stdio(false);
    int n, y;
    cin >> n >> y;

    for (int i = 0; i <= y / 10000; i++) {
        for (int j = 0; j <= (y - 10000 * i) / 5000; j++) {
            int k = n - i - j;
            if (10000 * i + 5000 * j + 1000 * k == y) {
                printf("%d %d %d\n", i, j, k);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}
