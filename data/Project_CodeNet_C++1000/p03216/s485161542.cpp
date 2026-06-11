#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pdi pair<db,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define eps 1e-8
#define MAXN 1000005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
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
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
	out(x / 10);
    }
    putchar('0' + x % 10);
}
char s[MAXN];
int N,Q,K;
int val[MAXN],add;
int que[MAXN],ql,qr;

void Solve() {
    read(K);
    ql = 1;qr = 0;
    add = 0;
    int64 sum = 0,ans = 0;
    for(int i = N ; i >= 1 ; --i) {
	if(s[i] == 'C') {que[++qr] = i;val[i] = -add;sum += val[i];}
	else if(s[i] == 'M') ++add;
	else if(s[i] == 'D'){
	    while(ql <= qr && que[ql] - i >= K) {sum -= val[que[ql++]];}
	    if(ql <= qr) {
		ans += sum + 1LL * add * (qr - ql + 1);
	    }
	}
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    read(N);
    scanf("%s",s + 1);
    read(Q);
    while(Q--) {
	Solve();
    }
}
