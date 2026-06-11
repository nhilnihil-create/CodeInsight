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

    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    const int INF = 1 << 28;
    vector<int> mins(2, INF);
    vector<int> maxs(2, -INF);

    for (int i = 0; i < n; ++i) {
        auto& mn = mins[0];
        auto& mx = maxs[0];
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    for (int i = 0; i < m; ++i) {
        auto& mn = mins[1];
        auto& mx = maxs[1];
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    bool res = false;
    if (maxs[0] < mins[1]) {
        // cout << mins[1]  << " " << maxs[0] << endl;
        if (mins[1] > X && maxs[0] < Y) {
            res = true;
        }
    }
    if (res) {
        cout << "No War\n";
    } else {
        cout << "War\n";
    }

    return 0;
}