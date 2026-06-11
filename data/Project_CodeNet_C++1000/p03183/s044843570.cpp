#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

struct Block {
    int weight, solidness, value;

    bool operator<(const Block& that) const {
        return solidness + weight < that.solidness + that.weight;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<Block> blocks(N);
    for (int i = 0; i < N; ++i) {
        cin >> blocks[i].weight >> blocks[i].solidness >> blocks[i].value;
    }

    sort(blocks.begin(), blocks.end());

    // dp[i][j] = from first i blocks, make a tower of total weight j
    // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - weight] if i j - weight < solidness)

    int max_solidness = max_element(blocks.begin(), blocks.end(), [](Block a, Block b) {
        return a.solidness < b.solidness;
    })->solidness;

    int max_weight = max_element(blocks.begin(), blocks.end(), [](Block a, Block b) {
        return a.weight < b.weight;
    })->weight;

    vector<int64_t> dp(max_solidness + max_weight + 1, 0);
    for (auto &block : blocks) {
        vector<int64_t> next(max_solidness + max_weight + 1, 0);
        for (int i = 0; i <= max_solidness + max_weight; ++i) {
            next[i] = dp[i];
            if (i > 0)
                next[i] = max(next[i], next[i - 1]);
            if (i >= block.weight && i - block.weight <= block.solidness)
                next[i] = max(next[i], dp[i - block.weight] + block.value);
        }
        dp = std::move(next);
    }

    cout << dp.back() << "\n";
}
