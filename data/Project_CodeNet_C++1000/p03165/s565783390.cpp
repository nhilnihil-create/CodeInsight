#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
const int mod = 998244353, maxn = 1e5+10;
int N, M, K;
int dp[3030][3030], path[3030][3030][2];
char s[3030], t[3030];

int main()
{
    scanf("%s %s", s, t);
    int ls = strlen(s), lt = strlen(t);
    for(int i = 1; i <= ls; i++)
        for(int j = 1; j <= lt; j++)
        {
            if(dp[i][j-1] > dp[i-1][j])
                path[i][j][0] = path[i][j-1][0], path[i][j][1] = path[i][j-1][1];
            else
                path[i][j][0] = path[i-1][j][0], path[i][j][1] = path[i-1][j][1];
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(dp[i-1][j-1]+(s[i-1]==t[j-1]) > dp[i][j])
            {
                dp[i][j] = dp[i-1][j-1]+(s[i-1]==t[j-1]);
                path[i][j][0] = i-1, path[i][j][1] = j-1;
            }
        }
//    printf("%d\n", dp[ls][lt]);
    int cnt = dp[ls][lt], px = path[ls][lt][0], py = path[ls][lt][1];
    stack<char> sta;
    while(cnt--) {
        sta.push(s[px]);
        ls = px, lt = py;
        px = path[ls][lt][0], py = path[ls][lt][1];
    }
    while(!sta.empty()) {
        printf("%c", sta.top());
        sta.pop();
    }
    return 0;
}
