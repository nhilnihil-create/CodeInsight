#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
const int N = 200001;
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
void put(int x) {
	if(x < 0) x = -x, putchar('-');
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int A[N], B[N];

int main() {
	int n = read();
	LL ans = 0, zz = 1e9 + 1;
	int cc = 0;
	for(int i = 1; i <= n; i++) {
		A[i] = read(), B[i] = read();
		if(A[i] == B[i]) cc++;
		ans += B[i];
		if(A[i] > B[i]) zz = _min(zz, B[i]);
	} if(zz == 1e9 + 1 || ans == 0) ans = 0;
	else ans = ans - zz;
	printf("%lld\n", ans);
	return 0;
}
