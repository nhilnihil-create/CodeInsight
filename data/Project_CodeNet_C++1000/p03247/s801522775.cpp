#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>
using namespace std;
#define fors(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) < (y) ? (y) : (x))
#define swap(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))
#define abs(x) ((x) < 0 ? -(x) : (x)) 
const int maxn=1e6+7;
typedef long long ll;
const int inf=1<<25;
int read(){
    int s=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0' && c<='9') {s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0) {putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+48);
}
const int N = 1e3 + 5;
 
int a[N], b[N];
int n, m, c, flag;
char s[45];
 
 
int main(){
 
    scanf("%d", &n);
    c = 0;
 
    fors(i, 1, n){
        scanf("%d%d", a + i, b + i);
        if ((a[i] + b[i]) & 1) ++c;
        else --c;
    }
 
    if (abs(c) != n) return 0 * puts("-1");
 
    m = 31 + (c < 0);
 
    printf("%d\n", m);
    fors(i, 0, 30) printf("%d ", 1 << i);
    if (c < 0) putchar(49);
    putchar(10);
 
    fors(i, 1, n){
        int x = a[i], y = b[i];
        if (c < 0) s[31] = 'R', --x;
        flag = 0;
        ford(j, 30, 0){
            if (abs(x) < abs(y)) swap(x, y), flag ^= 1;
            if (x > 0) x -= 1 << j, s[j] = flag ? 'U' : 'R';
            else x += 1 << j, s[j] = flag ? 'D' : 'L';
        }
 
        puts(s);
    }
 
    return 0;
}
 