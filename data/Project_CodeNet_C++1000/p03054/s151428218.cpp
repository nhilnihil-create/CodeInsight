#include <bits/stdc++.h>
using namespace std;

#define N 200005

char s[N], t[N];

int n, h, w;
int sx, sy;

int main() {
	scanf("%d %d %d", &h, &w, &n);
	scanf("%d %d", &sx, &sy);
    scanf("%s %s", s, t);
    int ty = sy; bool flag = 0;
    for (int i = 0; i < n && !flag; i ++) {
        if (s[i] == 'R') ty ++;
        if (ty > w) flag = 1;
        if (t[i] == 'L' && ty > 1) ty --;
    }
    ty = sy;
    for (int i = 0; i < n && !flag; i ++) {
        if (s[i] == 'L') ty --;
        if (ty < 1) flag = 1;
        if (t[i] == 'R' && ty < w) ty ++;
    }
    int tx = sx;
    for (int i = 0; i < n && !flag; i ++) {
        if (s[i] == 'U') tx --;
        if (tx < 1) flag = 1;
        if (t[i] == 'D' && tx < h) tx ++;
    }
    tx = sx;
    for (int i = 0; i < n && !flag; i ++) {
        if (s[i] == 'D') tx ++;
        if (tx > h) flag = 1;
        if (t[i] == 'U' && tx > 1) tx --;
    }
    puts(flag ? "NO" : "YES");
	return 0;
}
