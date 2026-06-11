#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

const int N = 1e3 + 100;
const int W = 2e4;

ll dp[W+100];

struct Block {
    int w, s, v;
};

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Block> blocks(n);
    for (Block& b : blocks) {
        cin >> b.w >> b.s >> b.v;
    }
    sort(all(blocks), [](Block x, Block y) {
        return y.s-x.w > x.s-y.w;
    });
    for (Block b : blocks) {
        for (int i=min(b.s, W-b.w); i>=0; i--) {
            dp[i+b.w] = max(dp[i+b.w], dp[i]+b.v);
        }
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
}
