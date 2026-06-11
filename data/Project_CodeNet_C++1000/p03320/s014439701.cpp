#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 100005
//#define ivorysi
using namespace std;
typedef long long int64;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
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
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) out(x / 10);
    putchar('0' + x % 10);
}
int K,t[25],tot,cnt,s[10005];
int64 L[10005],p[25],b[25];
int S(int64 x) {
    int res = 0;
    while(x) {res += x % 10;x /= 10;}
    return res;
}


int64 f(int64 x) {
    tot = 0;cnt = 0;int64 h = x;
    while(h) {t[++tot] = h % 10;h /= 10;}
    int64 num = 0;
    for(int i = tot ; i >= 1 ; --i) {
	for(int j = t[i] ; j <= 9 ; ++j) {
	    int64 tmp = num + j * b[i - 1] + p[i - 1];
	    if(tmp >= x) L[++cnt] = tmp;
	}
	num = num + t[i] * b[i - 1];
    }
    
    for(int i = 1 ; i <= cnt ; ++i) s[i] = S(L[i]);
    int r = 1;
    for(int i = 2 ; i <= cnt ; ++i) {
	int64 h = L[i] * s[r] - L[r] * s[i];
	if(h < 0) r = i;
	else if(h == 0 && L[i] < L[r]) r = i; 
    }
    return L[r];
}
void Solve() {
    read(K);
    int64 N = 1;
    p[1] = 9;
    for(int i = 2 ; i <= 16 ; ++i) p[i] = p[i - 1] * 10 + 9;
    b[0] = 1;
    for(int i = 1 ; i <= 16 ; ++i) b[i] = b[i - 1] * 10;
    while(K--) {
	out(N);enter;
	N = f(N + 1);
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}