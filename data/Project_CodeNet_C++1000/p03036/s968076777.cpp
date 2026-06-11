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
    int r, D, x2000;
    cin >> r >> D >> x2000;

    int xi = x2000;
    for (int i = 0; i < 10; i++) {
        xi = r * xi - D;
        cout << xi << endl;
    }

        return 0;
}
