#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int n;
vector<int> node[100005];
vector<pair<long long, long long>> dp;
vector<bool> visited;

long long dfs(int cur, long long &w, long long &b)
{
    visited[cur] = true;
    for(auto v : node[cur]) {
        long long w1, b1, x;
        if(!visited[v]){
            x = dfs(v, w1, b1);
            dp[cur].first *= x;
            dp[cur].first %= mod;
            dp[cur].second *= w1;
            dp[cur].second %= mod;
        }
    }
    w = dp[cur].first;
    return (dp[cur].first + dp[cur].second)%mod;
}

int main()
{
    scanf("%d", &n);
    dp = vector<pair<long long, long long>>(n+1, {1, 1});
    visited = vector<bool>(n+1, false);
    for(int i = 0; i < n-1; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        node[x].push_back(y);
        node[y].push_back(x);
    }
    long long w, b;
    printf("%lld\n", dfs(1, w, b));
}
