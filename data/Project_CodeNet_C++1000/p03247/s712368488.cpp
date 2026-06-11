#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b)    for (int i(a); i <= (b); ++i)
#define dec(i, a, b)    for (int i(a); i >= (b); --i)
#define MP      make_pair
#define fi      first
#define se      second
 
 
typedef long long LL;
 
const int N = 1e3 + 5;
 
int a[N], b[N];
int n, m, c, fg;
char s[45];
 
 
int main(){
 
    scanf("%d", &n);
    c = 0;
 
    rep(i, 1, n){
        scanf("%d%d", a + i, b + i);
        if ((a[i] + b[i]) & 1) ++c;
        else --c;
    }
 
    if (abs(c) != n) return 0 * puts("-1");
 
    m = 31 + (c < 0);
 
    printf("%d\n", m);
    rep(i, 0, 30) printf("%d ", 1 << i);
    if (c < 0) putchar(49);
    putchar(10);
 
    rep(i, 1, n){
        int x = a[i], y = b[i];
        if (c < 0) s[31] = 'R', --x;
        fg = 0;
        dec(j, 30, 0){
            if (abs(x) < abs(y)) swap(x, y), fg ^= 1;
            if (x > 0) x -= 1 << j, s[j] = fg ? 'U' : 'R';
            else x += 1 << j, s[j] = fg ? 'D' : 'L';
        }
 
        puts(s);
    }
 
    return 0;
}
 