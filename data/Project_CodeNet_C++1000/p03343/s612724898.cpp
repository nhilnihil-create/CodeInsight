#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 2005
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
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
	out(x / 10);
    }
    putchar('0' + x % 10);
}
int N,K,Q;
int a[MAXN],val[MAXN],tot;

bool check(int mid) {
    for(int i = 1 ; i <= tot ; ++i) {
	int l = val[i],r = val[i] + mid;
	int res = 0,st = 0,ed = -1,cnt = 0;
	for(int j = 1 ; j <= N ; ++j) {
	    if(a[j] >= l) {
		if(!st) st = ed = j;
		ed = max(ed,j);
		if(a[j] <= r) ++cnt;
	    }
	    else {
		if(ed - st + 1 >= K) {
		    res += min(cnt,(ed - st + 1) - K + 1);
		}
		st = 0,ed = -1;cnt = 0;
	    }
	}
	if(ed - st + 1 >= K) {
	    res += min(cnt,(ed - st + 1) - K + 1);
	}
	if(res >= Q) return true;
    }
    return false;
}
void Init() {
    read(N);read(K);read(Q);
    for(int i = 1 ; i <= N ; ++i) {
	read(a[i]);
	val[i] = a[i];
    }
    sort(val + 1,val + N + 1);
    tot = unique(val + 1,val + N + 1) - val - 1;
    
}
void Solve() {
    int L = 0,R = val[tot] - val[1];
    while(L < R) {
	int mid = (L + R) >> 1;
	if(check(mid)) R = mid;
	else L = mid + 1;
    }
    out(L);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Init();
    Solve();
}
