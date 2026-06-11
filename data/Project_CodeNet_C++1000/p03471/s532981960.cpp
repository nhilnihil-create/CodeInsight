#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N, Y;
    cin >> N >> Y;

    for (int x = 0; x <= 2000; ++x) {
        for (int y = 0; y <= 2000; ++y) {
            int z = N - x - y;
            if (z < 0 || N < z) {
                continue;
            }

            if (10000 * x + 5000 * y + 1000 * z == Y) {
                cout << x << ' ' << y << ' ' << z << endl;
                return 0;
            }
        }
    }

    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0;
}
