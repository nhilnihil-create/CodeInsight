#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;
const int INF = 1000000000;

int N; vector<int> dp;
void input()
{
    cin >> N;
}

void solve()
{
    dp.assign(100010,INF);
    dp[0] = 0;
    // DP1
    // for (int n = 1; n <= N; ++n){
    //     for (int i = 1; i <= n; i *= 6){
    //         dp[n] = min (dp[n], dp[n-i]+1);
    //     }
    //     for (int i = 1; i <= n; i *= 9){
    //         dp[n] = min (dp[n], dp[n-i]+1);
    //     }
    // }
    // cout << dp[N] << endl;
    
    // DP2
    for (int n = 0; n <= N; ++n){
        for (int i = 1; i + n <= N; i *= 6){
            dp[n+i] = min (dp[n+i], dp[n]+1);
        }
        for (int i = 1; i + n <= N; i *= 9){
            dp[n+i] = min (dp[n+i], dp[n]+1);
        }
    }
    cout << dp[N] << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}