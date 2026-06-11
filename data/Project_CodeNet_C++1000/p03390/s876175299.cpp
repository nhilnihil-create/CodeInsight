#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int _max(int x, int y) {return x > y ? x : y;}
const int N = 200001;
const int mod = 924844033;
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	int T = read();
	while(T--) {
		int a = read(), b = read();
		LL hh = (LL)a * b - 1;
		if(hh == 0) {puts("0"); continue;}
		int l = 1, r = 1e9, uu = 0;
		while(l <= r) {
			int mid = (l + r) / 2;
			if((LL)mid * mid <= hh) l = mid + 1, uu = mid;
			else r = mid - 1;
		} int ans = uu * 2;
		if(uu == hh / uu) ans--;
		if(a == uu && b == uu) ans--;
		else {
			if(a <= uu) ans--;
			if(b <= uu) ans--;
		} put(ans), puts("");
	}
	return 0;
}