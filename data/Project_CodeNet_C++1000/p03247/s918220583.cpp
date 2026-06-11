/*
 　　　　　／＞　 フ
 　　　　　| 　_　 _|
 　 　　　／`ミ _x 彡
 　　 　 /　　　 　 |
 　　　 /　  ヽ　　 ?
 　／￣|　　 |　|　|
 　| (￣ヽ＿_ヽ_)_)
 　＼二つ
  */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 2005;
ll len[N], x[N], y[N], cnt, n;
inline ll jue(ll x) { return x > 0 ? x : -x; }
int main() {
    read(n);
    for (int i = 1;i <= n; i++) {
        read(x[i]), read(y[i]);
        int t = (x[i] + y[i]) & 1;
        t ^= (x[1] + y[1]) & 1;
        if (t) { puts("-1"); return 0; }
    }
    if (!((x[1] + y[1]) & 1)) len[++cnt] = 1;
    write(cnt + 33);
    for (int i = 0;i <= 32; i++) len[++cnt] = 1ll << i;
    for (int i = cnt;i ; i--) write(len[i], ' ');
    puts("");
    for (int i = 1;i <= n; i++) {
        ll dx = 0, dy = 0;
        for (int j = cnt;j >= 1; j--) {
            ll tx = jue(x[i] - dx), ty = jue(y[i] - dy);
            if (tx >= ty) {
                if (x[i] > dx) { putchar('R'); dx += len[j]; }
                else { putchar('L'); dx -= len[j]; }
            }
            else {
                if (y[i] > dy) { putchar('U'); dy += len[j]; }
                else { putchar('D'); dy -= len[j]; }
            }
        }
        puts("");
    }
    return 0;
}
