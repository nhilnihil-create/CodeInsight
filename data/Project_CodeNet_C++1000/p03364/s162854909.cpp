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

char str[305][305];
int  a[305][305];

void solve()
{
    int n;
    scanf("%d", &n);
    int i, j, k;
    for (i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                int i2 = (i + k) % n, j2 = (j + k) % n;
                if (str[i2][j] != str[i][j2]) {
                    break;
                }
            }
            a[i][j] = k;
        }
    }

    int cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                int i2 = (i + k) % n, j2 = (j + k) % n;
                if (a[i2][j2] < n - k) {
                    break;
                }
            }
            if (k == n) cnt++;
        }
    }
    printf("%d\n", cnt);

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
