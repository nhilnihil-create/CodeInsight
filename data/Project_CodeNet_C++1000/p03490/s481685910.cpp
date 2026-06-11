#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 16010;
const int BASE = 8000;
char s[MAXN];
int dpx[MAXN], dpy[MAXN];
int tmp[MAXN];
vector<int> x, y;

int main() {
    scanf("%s", s);
    int n = strlen(s), tgx, tgy;
    s[n] = 'T';
    scanf("%d %d", &tgx, &tgy);
    int isX = 1, cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == 'F') cnt++;
        else {
           if (isX) x.push_back(cnt);
           else y.push_back(cnt);
           isX ^= 1;
           cnt = 0;
        }
    }
    dpx[x[0] + BASE] = 1;
    for (int i = 1; i < (int)x.size(); i++) {
        memset(tmp, 0, sizeof(tmp));
        int cur = x[i];
        for (int j = 0; j < MAXN; j++) {
            if (j + cur < MAXN && dpx[j + cur]) tmp[j] = 1;
            if (j - cur >= 0 && dpx[j - cur]) tmp[j] = 1;
        }
        for (int j = 0; j < MAXN; j++)
            dpx[j] = tmp[j];
    }
    dpy[BASE] = 1;
    for (int i = 0; i < (int)y.size(); i++) {
        memset(tmp, 0, sizeof(tmp));
        int cur = y[i];
        for (int j = 0; j < MAXN; j++) {
            if (j + cur < MAXN && dpy[j + cur]) tmp[j] = 1;
            if (j - cur >= 0 && dpy[j - cur]) tmp[j] = 1;
        }
        for (int j = 0; j < MAXN; j++)
            dpy[j] = tmp[j];
    }
    if (!dpx[tgx + BASE] || !dpy[tgy + BASE]) puts("No");
    else puts("Yes");
    return 0;
}
