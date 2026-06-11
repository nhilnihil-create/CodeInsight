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
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

int d[30][30];
int cnt[3][30];
ll s[3][30];

void solve()
{
    int N, n;
    scanf("%d%d", &N, &n);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &d[i][j]);
        }
    }

    /*for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);*/

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            int c;
            scanf("%d", &c); c--;
            int k = (i + j) % 3;
            cnt[k][c]++;
        }
    }
    ll ans = LINF;
    for (i = 0; i < 3; i++) {
        int k;        
        for (k = 0; k < n; k++) {
            for (j = 0; j < n; j++) {
                s[i][k] += (ll)d[j][k] * cnt[i][j];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            int k;
            for (k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                ll tmp=s[0][i] + s[1][j] + s[2][k];
                ans = MIN(ans, tmp);
            }
        } 
    }

    printf("%lld\n", ans);
 

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
