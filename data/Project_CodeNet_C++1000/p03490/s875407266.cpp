#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <numeric>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template <typename It>
bool can_sum(It begin, It end, int64_t s) {
    constexpr auto kMax = 10000;
    constexpr auto kOffset = kMax;

    bitset<kMax * 2 + 1> current;

    if (begin == end) {
        return (s == 0);
    }

    if (s + kOffset < 0 || s >= kMax + kOffset) {
        return false;
    }

    current[0 + kOffset] = true;
    for (auto it = begin; it != end; ++it) {
        auto v = *it;
        current = ((current << v) | (current >> v));
    }

    return current[s + kOffset];
}

bool solve(const string& s, int x, int y) {
    // 横移動, 縦移動
    vector<int> xmove(1), ymove;

    bool current_xmove = true;
    for (auto ss : s) {
        if (ss == 'T') {
            current_xmove  = !current_xmove;
            if (current_xmove) {
                xmove.push_back(0);
            } else {
                ymove.push_back(0);
            }
            continue;
        }
        if (current_xmove) {
            ++xmove.back();
        } else {
            ++ymove.back();
        }
    }

    return can_sum(xmove.begin() + 1, xmove.end(), x - xmove[0]) && can_sum(ymove.begin(), ymove.end(), y);
}

int main() {
    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    cout << (solve(s, x, y) ? "Yes" : "No") << endl;

    return 0;
}