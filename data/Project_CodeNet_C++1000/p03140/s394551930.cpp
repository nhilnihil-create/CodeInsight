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

char a[105], b[105], c[105];

void solve()
{
    int n;
    scanf("%d%s%s%s", &n, &a, &b, &c);
    int i;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] == c[i]) {
            ;
        }
        else if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) {
            cnt++;
        }
        else {
            cnt += 2;
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
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
