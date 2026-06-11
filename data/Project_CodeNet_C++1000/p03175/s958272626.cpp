/*

N 

3
1 2 
2 3



*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

const int nax = 1e5+5;

const int mod = 1e9+7;

int mul(int a, int b) {
    return (ll) a * b % mod;
}

int add(int a, int b) {
    return (a + b) % mod;
}

vector<vector<int>> adj_list(nax);

vector<int> dfs(int x, int parent) {
    // dp[0] - no. of ways to paint it white 
    // dp[1] - no. of ways to paint it black
    vector<int> dp(2);
    
    int all_white = 1;
    
    int sth_black = 0;
    
    for (int y : adj_list[x]) {
        if (y != parent) {
            vector<int> p = dfs(y, x);
            // p.first - no. of ways to paint 'y' white
            // p.second - no. of ways to paint 'y' black
            sth_black = add(mul(all_white, p[1]), mul(sth_black, add(p[0], p[1])));
            all_white = mul(all_white, p[0]);
        }
    }
    
    dp[0] = add(all_white, sth_black); // paint this as white
    
    dp[1] = all_white; // paint this as black
    
    return dp;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; i++) {
        int xi;
        int yi;
        scanf("%d%d", &xi, &yi);
        adj_list[xi].push_back(yi);
        adj_list[yi].push_back(xi);
    }
    
    vector<int> ans = dfs(1, -1);
    
    printf("%d", add(ans[0], ans[1]));
    
	return 0;
}