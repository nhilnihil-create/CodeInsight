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

char s[100005];
int acnt, bcnt, ccnt;

int n;

bool check(const char* S)
{
    int n_acnt = 0, n_bcnt = 0, n_ccnt = 0;
    for (int i = 1; i <= n; i++) {
        char chr = S[(i - 1) % 3];
        if (chr == 'a') n_acnt++;
        if (chr == 'b') n_bcnt++;
        if (chr == 'c') n_ccnt++;
    }
    return n_acnt == acnt && n_bcnt == bcnt && n_ccnt == ccnt;
}

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') acnt++;
        else if (s[i] == 'b') bcnt++;
        else ccnt++;
    }
    if (check("abc") || check("acb") || check("bac") || check("bca")
        || check("cab") || check("cba")) {
            printf("YES");
        } else {
            printf("NO");
        }
    return 0;
}
