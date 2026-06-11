#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int>ki[100005];
int dp[100005][2];
void dfs(int now) {
    dp[now][0] = dp[now][1] = 1;
    for(int i = 0; i < ki[now].size(); i++) {
        if(dp[ki[now][i]][0] == 0) {
            dfs(ki[now][i]);
            dp[now][0] *= dp[ki[now][i]][0]+dp[ki[now][i]][1];
            dp[now][1] *= dp[ki[now][i]][0];
            dp[now][0] %= mod;
            dp[now][1] %= mod;
        }
    }
    return;
}
signed main(){
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        ki[a].push_back(b);
        ki[b].push_back(a);
    }
    dfs(0);
    cout << (dp[0][0]+dp[0][1])%mod << endl;
}
