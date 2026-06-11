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
#define mo 974711
#define MAXN 100005
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
int N,x,y,s,t;
char str[8005];
vector<int> dir[2];
bitset<16005> f[2];
bool cmp(int a,int b) {
    return a > b;
}
void Solve() {
    scanf("%s",str + 1);read(x);read(y);
    N = strlen(str + 1);
    int d = 0;
    s = 0,t = 0;
    int p = 1;
    while(p <= N && str[p] == 'F') {++s;++p;}
    int cnt = 0;
    for(int i = p ; i <= N ; ++i) {
	if(str[i] == 'T') {
	    if(cnt) dir[d].pb(cnt);
	    d ^= 1;cnt = 0;
	}
	else {++cnt;}
    }
    if(cnt) dir[d].pb(cnt);
    if(abs(s - x) > N) {puts("No");return;}
    int cur = 0;
    f[cur].reset();
    f[cur][8000] = 1;
    for(auto k : dir[0]) {
	f[cur ^ 1].reset();
	f[cur ^ 1] = (f[cur] << k) | (f[cur] >> k);
	cur ^= 1;
    }
    if(!f[cur][8000 + abs(s - x)]) {puts("No");return;}
    cur = 0;
    f[cur].reset();
    f[cur][8000] = 1;
    for(auto k : dir[1]) {
	f[cur ^ 1].reset();
	f[cur ^ 1] = (f[cur] << k) | (f[cur] >> k);
	cur ^= 1;
    }
    if(!f[cur][8000 + abs(t - y)]) {puts("No");return;}
    puts("Yes");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
