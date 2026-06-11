#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <cassert>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

char str[100005];
ll dp[4][100005];

void solve()
{
    scanf("%s", str);
    int n = strlen(str);
    dp[0][0] = 1;
    int i;
    for (i = 0; i < n; i++) {
        int mult = (str[i] == '?' ? 3 : 1);
        dp[0][i + 1] = dp[0][i]*mult%MOD;
        dp[1][i + 1] = dp[1][i]*mult%MOD;
        dp[2][i + 1] = dp[2][i]*mult%MOD;
        dp[3][i + 1] = dp[3][i]*mult%MOD;
        if (str[i] == 'A' || str[i] == '?') {
            dp[1][i + 1] = (dp[1][i + 1] + dp[0][i]) % MOD;
        }
        if (str[i] == 'B' || str[i] == '?') {
            dp[2][i + 1] = (dp[2][i + 1] + dp[1][i]) % MOD;
        }
        if (str[i] == 'C' || str[i] == '?') {
            dp[3][i + 1] = (dp[3][i + 1] + dp[2][i]) % MOD;
        }
    }
    printf("%lld\n", dp[3][n]);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

