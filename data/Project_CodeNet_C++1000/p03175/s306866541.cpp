#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;
vector<int> tree[100001];
int dp[100001][2];

// 0 = white, 1 = black
int solve(int curr, int color, int pr) {
    if(!tree[curr].size()) {
        if(color == 0) return 2;
        else return 1;
    }

    if(dp[curr][color] != -1) return dp[curr][color];

    int ans = 0, w1 = 1;
    for(auto child: tree[curr]) {
        if(child != pr) w1 = (w1*solve(child, 0, curr))%mod;
    }
    ans+= w1;

    if(!color) {
        int w2 = 1;
        for(auto child: tree[curr]) {
            if(child != pr) w2 = (w2*solve(child, 1, curr))%mod;
        }
        ans+= w2;
    }
    return dp[curr][color] = ans%mod;
}

int32_t main() {
    int N; cin>>N;
    for(int i=0; i<N-1; i++) {
        int x, y; cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(1, 0, -1)<<endl;
    return 0;
}
