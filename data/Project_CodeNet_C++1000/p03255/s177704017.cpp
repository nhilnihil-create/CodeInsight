#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define MAXN 200005
#define mo 994711
//#define ivorysi
using namespace std;
typedef unsigned long long int64;
typedef long double db;
typedef unsigned int u32;
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
    if(x >= 10) out(x / 10);
    putchar('0' + x % 10);
}
int64 x[MAXN],XV,sum[MAXN],ans;
pii que[MAXN];
int N; 
void Init() {
    read(N);read(XV);
        
    for(int i = 1 ; i <= N ; ++i) read(x[i]);
    ans = XV * (N + 1) + x[N] * 5;
    for(int i = 1 ; i < N ; ++i) {
    	ans += 1LL * (2 * i + 3) * x[N - i];
    }  
    for(int i = 1 ; i <= N ; ++i) {
    	sum[i] = sum[i - 1] + x[i];
    }
}
void Solve() {
    for(int K = 2 ; K <= N ; ++K) {
    	int64 tmp = (K + N) * XV,t = 1;
    	tmp += 5 * (sum[N] - sum[N - K]);
    	for(int r = N - K; r >= 1 ; r -= K) {
    	    int l = max(1,r - K + 1);
    	    tmp += (2 * t + 3) * (sum[r] - sum[l - 1]);
    	    ++t;
    	}
    	
    	ans = min(ans,tmp);
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Init();
    Solve();
    return 0;
}
