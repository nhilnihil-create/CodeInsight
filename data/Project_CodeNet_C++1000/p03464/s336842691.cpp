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


void solve()
{
    int K;
    scanf("%d", &K);
    vector<int> a(K);
    int i;
    for (i = 0; i < K; i++) {
        scanf("%d", &a[i]);
    }
    if (a[K-1] != 2) {
        printf("-1\n"); return;
    }
    ll min = 2, max = 2;
    int step = 1;
    for (i = K - 2; i >= 0; i--) {
        min = min;
        if (min%a[i]) {
            min += (a[i] - min % a[i]);
        }        
        max = max + a[i + 1] - 1;
        if (max%a[i]) {
            max = max - (max%a[i]);
        }
        if (min > max) {
            printf("-1\n"); return;
        }
    }

    {
        min = min;      
        max = max + a[0] - 1;
    }
    printf("%lld %lld\n", min, max);

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
