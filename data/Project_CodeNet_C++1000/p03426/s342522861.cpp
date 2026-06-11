#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, D; cin >> H >> W >> D;
    map<int, pair<int, int>> m;
    vector<ll> dp(H*W+1, -1);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int a; cin >> a;
            m[a] = make_pair(i, j);
        }
    }
    for (int i = 1; i < H*W+1; i++)
    {
        if(i-D < 1) dp[i] = 0;
        if(m.count(i-D)&&m.count(i)){
            dp[i] = dp[i-D] + abs(m[i-D].first - m[i].first)  + abs(m[i-D].second - m[i].second);
        }
    }
    

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int l, r; cin >> l >> r;
        cout << dp[r] - dp[l] << endl;
    }
}