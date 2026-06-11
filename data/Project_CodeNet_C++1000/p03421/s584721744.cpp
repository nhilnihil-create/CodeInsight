#include <bits/stdc++.h>
using namespace std;
#define M 300010
#define LL long long
#define rep(i, x, y) for(int i = (x); i <= (y); ++ i)
inline int read() {
	char ch = getchar(); int x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int a[M];
vector<int> res;
int main() {
	//freopen("in.txt", "r", stdin);
	int n = read(), A = read(), B = read();
	int now = n;
/*	if(n > A * B || A + B - 1 > n) {
		return puts("-1"), 0;
	}*/
	a[1] = A; n -= A;
	rep(i, 2, B) a[i] = 1, -- n;
	if(n < 0) return puts("-1"), 0;
	rep(i, 2, B) {
		if(n >= A - 1) {
			a[i] += A - 1;
			n -= A - 1;
			continue;
		}
		a[i] += n;
		n = 0;
		break;
	}
	if(n > 0) return puts("-1"), 0;
	rep(i, 1, B) {
		rep(j, now - a[i] + 1, now) {
			res.push_back(j);
		}
		now -= a[i];
	}
	for(int i = 0; i < res.size(); ++ i) {
		printf("%d ", res[i]);
	}
	return 0;
}
