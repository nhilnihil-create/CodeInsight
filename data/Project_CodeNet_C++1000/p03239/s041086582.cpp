#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    const int INF = 1 << 28;
    int res = INF;

    for (int i = 0; i < n; ++i) {
        int c, t;
        cin >> c >> t;
        if (t <= T) {
            res = min(res, c);
        }
    }

    if (res < INF) {
        cout << res << '\n';
    } else {
        cout << "TLE" << '\n';
    }


    return 0;
}