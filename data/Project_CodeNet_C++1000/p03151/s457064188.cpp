#include <bits/stdc++.h>

using namespace std;

#define reg register
#define ge getchar()
#define Re read()
#define ll long long
#define MAXN 100100

inline int read() {
	reg int x = 0, t = 0, ch;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = ge;
	return t ? -x : x;
}

int a[MAXN + 1];
int b[MAXN + 1];
int cut[MAXN + 1];

int main() {
	int n = Re;
	ll sum = 0;
	ll nd = 0;
	int res = 0;
	for(reg int i = 1; i <= n; i++) {
		a[i] = Re;
		sum += a[i];
	}
	for(reg int i = 1; i <= n; i++) {
		b[i] = Re;
		sum -= b[i];
		cut[i] = a[i] - b[i];
		nd += cut[i] < 0 ? cut[i] : 0;
		res += cut[i] < 0;
	}
	if(sum < 0) puts("-1");
	else {
		sort(cut + 1, cut + 1 + n);
		for(reg int i = n; i >= 0; i--) {
			if(nd >= 0) {printf("%d\n", n - i + res); return 0;}
			nd += cut[i];
		}
	}
	return 0;
}