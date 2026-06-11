#include <algorithm>
#include <climits>
#include <cstring>
#include <cctype>
#include <inttypes.h>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int cap = 3001;
int N;
char s[cap];
int dp[cap][cap];

int add(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N; ++i)
        scanf(" %c", &s[i]);
    fill(&dp[0][0], &dp[0][0] + cap * cap, 0);
    dp[1][1] = 1;

    for (int i = 1; i < N; ++i) {
        if (s[i] == '<') {
            for (int j = 2; j <= i + 1; ++j) {
                dp[i + 1][j] = add(dp[i + 1][j - 1], dp[i][j - 1]);
            }
        }
        else {
            for (int j = i; j > 0; --j) {
                dp[i + 1][j] = add(dp[i + 1][j + 1], dp[i][j]);
            }
        }
        // for (int j = 1; j <= N; ++j)
        //     printf("%d ", dp[i + 1][j]);
        // printf("\n");
    }
    
    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = add(ans, dp[N][i]);
    printf("%d\n", ans);
}



