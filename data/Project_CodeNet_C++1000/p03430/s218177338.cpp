#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

short dp[301][301][301];
string ss;

int dfs(int l, int r, int k) {
    if (dp[l][r][k] != -1) return dp[l][r][k];
    if (l == r) return 1;
    if (l > r) return 0;


    int ans = 0;
    if (k > 0) {
        ans = max(ans, dfs(l + 1, r - 1, k - 1) + 2); // replace l or r
    }
    ans = max(ans, dfs(l + 1, r, k)); // abandon l
    ans = max(ans, dfs(l, r - 1, k)); // abandon r

    if (ss[l] == ss[r]) {
        ans = max(ans, dfs(l + 1, r - 1, k) + 2);
    }
    return dp[l][r][k] = ans;
}

void solve(string S, ll K) {
    ss = S;
    memset(dp, -1, sizeof(dp));
    
    cout << dfs(0, S.size() - 1, K) << endl;
}

int main() {
    ll K;
    string S;
    cin >> S;
    scanf("%lld", &K);
    solve(S, K);
    return 0;
}

