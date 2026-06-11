#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_W = 20000;

struct Block {
    ll w, s, v;    
    Block(ll w=0LL, ll s=0LL, ll v=0LL): w(w), s(s), v(v) {}
    bool operator<(const Block b) const{
        return w+s < b.w+b.s;
    }
};

ll dp[2][MAX_W+1];

int main() {
    int n;
    cin >> n;
    vector<Block> blocks(n);
    for(int i=0;i<n;++i) {
        cin >> blocks[i].w >> blocks[i].s >> blocks[i].v;
    }
    sort(blocks.begin(), blocks.end());

    // 上から置いていく
    dp[0][0] = 0LL;
    for(int i=0;i<n;++i) {
        int i_mlb = i & 1;
        for(int j=0;j<=MAX_W;++j) {
            dp[1-i_mlb][j] = max(dp[1-i_mlb][j], dp[i_mlb][j]);
            if(j+blocks[i].w <= MAX_W && j <= blocks[i].s) {
                dp[1-i_mlb][j+blocks[i].w] = max(dp[1-i_mlb][j+blocks[i].w], dp[i_mlb][j] + blocks[i].v);
            }
        }
    }

    ll ans = *max_element(dp[n&1], dp[n&1]+MAX_W+1);
    cout << ans << "\n";
}