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

int h, w, n;
int sr, sc;

char s[200005];
char t[200005];

bool check(int cur, char dec, char inc, int maxv)
{
    int left = 1;
    int right = maxv;
    for (int i = n; i >= 1; i--) {
        if (s[i] != dec && s[i] != inc) {
            if (t[i] == dec) right++;
            if (t[i] == inc) left--;
        } else if (t[i] != dec && t[i] != inc) {
            if (s[i] == dec) left++;
            if (s[i] == inc) right--;
        } else {
            if (s[i] == t[i]) {
                if (s[i] == dec) {
                    left++, right++;
                } else {
                    left--, right--;
                }
            } else {
                if (s[i] == dec) {
                    left = max(left, 2);
                } else {
                    right = min(right, maxv - 1);
                }
            }
        }
        left = max(left, 1);
        right = min(right, maxv);
        if (left > right) return true;
    }
    return cur < left || cur > right;
}

int main()
{
    scanf("%d%d%d", &h, &w, &n);
    scanf("%d%d", &sr, &sc);
    scanf("%s%s", s + 1, t + 1);
    if (check(sc, 'L', 'R', w) || check(sr, 'U', 'D', h)) {
        printf("NO");
    } else {
        printf("YES");
    }
    return 0;
}
