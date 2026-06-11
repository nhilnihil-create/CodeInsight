#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

vector<int> G[100010];
int dp[100010];
int dfs(int x, int p = -1) {
    if(dp[x] != -1) return dp[x];
    int ret = 0;
    for(auto to: G[x]) {
        if(to == p) continue;
        ret = max(ret, dfs(to, x) + 1);
    }
    return dp[x] = ret;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }
    rep(i, 100010) dp[i] = -1;
    int ans = 0;
    rep(i, N) ans = max(ans, dfs(i));
    cout << ans << endl;



    return 0;
}
