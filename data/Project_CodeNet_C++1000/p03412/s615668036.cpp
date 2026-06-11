#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define space putchar(' ')
#define enter putchar('\n')
#define mp make_pair
#define MAXN 200005
#define pb push_back
//#define ivorysi
using namespace std;
typedef long long int64;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
    	if(c == '-') f = -1;
    	c = getchar();
    }
    while(c >= '0' && c <= '9') {
    	res = res * 10 + c - '0';
    	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {putchar('-');x = -x;}
    if(x >= 10) {
    	out(x / 10);
    }
    putchar('0' + x % 10);
}
int N;
int a[MAXN],b[MAXN];
int val[2][MAXN],len[2];
bool check(int p) {
    len[0] = len[1] = 0;
    for(int i = 1 ; i <= N ; ++i) {
        if(a[i] & (1 << p)) val[1][++len[1]] = a[i] & (1 << p) - 1;
        else val[0][++len[0]] = a[i] & (1 << p) - 1;
    }
    sort(val[1] + 1,val[1] + len[1] + 1);
    sort(val[0] + 1,val[0] + len[0] + 1);
    int64 res = 0;
    for(int i = 1 ; i <= N ; ++i) {
        int t = (1 << p) - (b[i] & (1 << p) - 1);
        int p0,p1;
        p0 = lower_bound(val[0] + 1,val[0] + len[0] + 1,t) - val[0] - 1;
        p1 = lower_bound(val[1] + 1,val[1] + len[1] + 1,t) - val[1] - 1;
        if(b[i] & (1 << p)) {res += p0;res += len[1] - p1;}
        else {res += p1;res += len[0] - p0;}
    }
    return res & 1;
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {read(a[i]);}
    for(int i = 1 ; i <= N ; ++i) {read(b[i]);}
    int ans = 0;
    for(int i = 28 ; i >= 0 ; --i) {
        if(check(i)) ans |= (1 << i);
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
