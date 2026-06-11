#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int n;
Int w[1100], s[1100], v[1100];
Int dp[1100][22000];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> w[i] >> s[i] >> v[i];
    vector<int> blocks;
    for(int i = 0;i < n;i++)blocks.push_back(i);
    sort(blocks.begin(), blocks.end(), [&](int x, int y){return s[x] + w[x] < s[y] + w[y];});

    for(int i = 1;i <= n;i++){
        int ind = blocks[i-1];
        for(int j = 0;j < 22000;j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[ind] <= s[ind] && j-w[ind] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[ind]] + v[ind]);
            }
        }
    }
    Int ans = 0;
    for(int j = 0;j < 22000;j++){
        ans = max(ans, dp[n][j]);        
    }
    cout << ans << endl;
    return 0;
}