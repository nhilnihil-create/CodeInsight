#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
inline char nc() {
	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
const int maxH = 2e5 + 5;
int H, W, N;
int mn[maxH];
int solve() {
	int mx = 0;
	for(int i = 1; i <= H; ++i) {
		if(mn[i] != mx + 1) ++mx;
		if(mx >= mn[i]) return i - 1;
	}
	return H;
}
int main() {
	read(H), read(W), read(N);
	for(int i = 1; i <= H; ++i) mn[i] = W + 1;
	for(int i = 1; i <= N; ++i) {
		int x, y; read(x), read(y);
		mn[x] = min(mn[x], y);
	}
	printf("%d\n", solve());
	return 0;
}