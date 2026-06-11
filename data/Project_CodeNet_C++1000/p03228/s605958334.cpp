#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
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



void solve()
{
    int a, b, K;
    scanf("%d%d%d", &a, &b, &K);
    int i;
    for (i = 0; i < K; i++) {
        if (i % 2 == 0) {
            if (a % 2) a--;
            a = a / 2;
            b += a;
        }
        else {
            if (b % 2) b--;
            b = b / 2;
            a += b;
        }
    }
    printf("%d %d\n", a, b);

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
