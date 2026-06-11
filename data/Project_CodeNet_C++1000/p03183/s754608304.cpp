#include <iostream>
#include <algorithm>
#include <vector>

using Int = long long int;
using std::vector;

constexpr Int INF = std::numeric_limits<Int>::max() / 3;
constexpr int S = 10000;

struct Block {
    int w, s;
    Int v;
    bool operator<(const Block& b) const {
        return w + s < b.w + b.s;
    }
};

int main() {
    int n;
    std::cin >> n;
    
    vector<Block> blocks(n);
    for(auto& b : blocks) {
        std::cin >> b.w >> b.s >> b.v;
    }
    std::sort(blocks.begin(), blocks.end());

    vector<Int> dp(S * 2 + 1, -INF);
    dp[0] = 0;
    // key is weight

    for(const auto& b : blocks) {
        for(int w = b.s; w >= 0; --w) {
            dp[w + b.w] = std::max(dp[w + b.w], dp[w] + b.v);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
    return 0;
}
