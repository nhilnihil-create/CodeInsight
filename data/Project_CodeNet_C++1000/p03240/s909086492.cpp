#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

const int N = 110;
const int mod = 10007;

inline int read() {
	int jg = 0, jk = getchar() - '0', f = 1;
	while(jk < 0 || jk > 9) {
	    if(jk == '-' - '0')  f = -1;
		jk = getchar() - '0';
	}
	while(jk >= 0 && jk <= 9)
		jg *= 10, jg += jk, jk = getchar() - '0';
	return jg * f;
}

int n, xa[N], ya[N], ha[N], h;

int main() {
	//freopen("a.txt", "r", stdin);
    n = read();
	for(int i = 1; i <= n; ++i)
		xa[i] = read(), ya[i] = read(), ha[i] = read();
	for(int i = 0; i <= 100; ++i)
		for(int j = 0, l; j <= 100; ++j) {
			l = 1;
			for(int k = 1; k <= n; ++k)
				if(ha[k]) {
					h = ha[k] + abs(i - xa[k]) + abs(j - ya[k]);
					break;
				}
			for(int k = 1; k <= n; ++k)
				if(max(0, h - abs(i - xa[k]) - abs(j - ya[k])) != ha[k]) {
					l = 0;
					break;
				} 
			if(l) {
				printf("%d %d %d\n", i, j, h);
				return 0;
			}
		}
	return 0;
}