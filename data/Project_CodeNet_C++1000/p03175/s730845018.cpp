#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

vector<vector<int>> edge;
vector<vector<ll>> dp;
ll mod = 1e9+7;

void dfs(int now, int par) {
    for (int nxt : edge[now]) {
        if (nxt == par) continue;
        dfs(nxt, now);
        dp[now][0] *= dp[nxt][0]+dp[nxt][1];
        dp[now][1] *= dp[nxt][0];
        dp[now][0] %= mod;
        dp[now][1] %= mod;
    }
    return;
}

int main() {
    int N;
    cin >> N;
    edge.resize(N);
    dp = vector<vector<ll>>(N, vector<ll>(2, 1));
    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(0, -1);
    cout << (dp[0][0]+dp[0][1])%mod << endl;
    return 0;
}