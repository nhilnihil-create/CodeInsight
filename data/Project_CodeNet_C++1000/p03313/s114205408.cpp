#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
void put(int x) {
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int bin[19], ans[1 << 18];
int a[1 << 18], mx1[1 << 18], mx2[1 << 18];

int main() {
	int n = read();
	bin[0] = 1; for(int i = 1; i <= 18; i++) bin[i] = bin[i - 1] << 1;
	for(int i = 0; i < bin[n]; i++) a[i] = read(), mx1[i] = a[i];
	for(int i = 1; i < bin[n]; i <<= 1) {
		for(int j = 0; j < bin[n]; j += i << 1) {
			for(int k = 0; k < i; k++) {
				if(mx1[j + k] > mx1[j + k + i]) mx2[j + k + i] = mx1[j + k + i], mx1[j + k + i] = mx1[j + k];
				else if(mx1[j + k] > mx2[j + k + i]) mx2[j + k + i] = mx1[j + k];
				if(mx2[j + k] > mx2[j + k + i]) mx2[j + k + i] = mx2[j + k];
			}
		}
	} for(int i = 1; i < bin[n]; i++) ans[i] = mx1[i] + mx2[i], ans[i] = _max(ans[i], ans[i - 1]);
	for(int i = 1; i < bin[n]; i++) put(ans[i]), puts("");
	return 0;
}
