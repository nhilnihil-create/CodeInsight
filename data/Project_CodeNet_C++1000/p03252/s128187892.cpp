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

char str0[200005];
char str1[200005];

void solve()
{
    scanf("%s%s", str0, str1);
    int n = strlen(str0);
    vector<int> v(26, -1);
    int i;
    for (i = 0; i < n; i++) {
        int tmp0 = str0[i] - 'a';
        int tmp1 = str1[i] - 'a';

        if (v[tmp0] >= 0) {
            if (v[tmp0] != tmp1) {
                printf("No\n"); return;
            }
        }
        else {
            v[tmp0] = tmp1;
        }
    }
    set<int> z;
    for (i = 0; i < 26; i++) {
        if (v[i] >= 0) {
            if (!z.insert(v[i]).second) {
                printf("No\n"); return;
            }
        }
    }
    printf("Yes\n");
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

