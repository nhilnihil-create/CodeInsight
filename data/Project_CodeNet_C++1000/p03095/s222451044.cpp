#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int cnt[30];
char s[100005];
int n;

int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        cnt[s[i] - 'a']++;
    }
    int ans = 1;
    for (int i = 0; i < 26; i++) {
        ans = mul(ans, cnt[i] + 1);
    }
    ans--;
    if (ans < 0) ans += MOD;
    printf("%d", ans);
    return 0;
}
