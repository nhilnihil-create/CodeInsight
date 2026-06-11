#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <ctime>
using namespace std;

int const MAX_N = 305;

string st;
int K_mx;

short int dp[MAX_N][MAX_N][MAX_N];

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    
    cin>>st>>K_mx;

    int n = (int) st.length();
    for (int i=0; i<n; i++)
        dp[i][i][0] = 1;

    for (int len=2; len<=n; len++)
        for (int i=0; i+len-1 < n; i++) {
            int j = i+len-1;
            for (int old_k = 0; old_k <= K_mx; old_k++) {
                dp[i][j][old_k] = max(dp[i][j][old_k], max(dp[i+1][j][old_k], dp[i][j-1][old_k]));
                if (st[i] == st[j])
                    dp[i][j][old_k] = max(dp[i][j][old_k], (short int) (dp[i+1][j-1][old_k] + 2));
                else if (old_k + 1 <= K_mx)
                    dp[i][j][old_k+1] = max(dp[i][j][old_k+1], (short int) (dp[i+1][j-1][old_k] + 2));
            }
        }

    short int ans = 0;
    for (int old_k=0; old_k<=K_mx; old_k++)
        ans = max(ans, dp[0][n-1][old_k]);
    cout<<ans;
   	return 0;
}