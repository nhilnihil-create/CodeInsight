#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1007;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char ch[] = {'R', 'L', 'U', 'D'};

LL a[50];
int n, x[N], y[N], c[2];
int len;
char ans[N];

inline LL calc(LL x, LL y) {
    LL ret = max(abs(x + y), abs(x - y));
    if(ret == 0) return -1;
    ret >>= 1;
    return lower_bound(a, a + 39, ret) - a;
}

void go(LL x, LL y, LL p) {
    if(!x && !y) return;
    LL step = 1LL << p;
    LL nx, ny;
    for(int dir = 0; dir < 4; dir++) {
        nx = x + dx[dir] * step;
        ny = y + dy[dir] * step;
        if(calc(nx, ny) <= p - 1) {
            ans[len++] = ch[dir ^ 1];
            go(nx, ny, p - 1);
            break;
        }
    }
}

int main() {
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i < 39; i++) {
        a[i] = a[i - 1] + (1LL << i - 1);
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        c[x[i] + y[i] & 1]++;
    }
    if(c[0] && c[1]) return puts("-1"), 0;
    if(c[1]) {
        puts("39");
        for(int i = 0; i < 39; i++) printf("%lld ", 1LL << i);
        puts("");
    }
    else {
        puts("40");
        for(int i = 0; i < 39; i++) printf("%lld ", 1LL << i);
        puts("1");
    }
    for(int i = 1; i <= n; i++) {
        len = 0;
        if(c[0]) x[i]--, ans[len++] = 'R';
        go(x[i], y[i], 38);
        ans[len] = '\0';
        reverse(ans, ans + len);
        puts(ans);
    }
    return 0;
}

/*
1
2 -1
*/
