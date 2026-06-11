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
char getc() {
	char ch = getchar();
	while(ch < 'A' || ch > 'Z') ch = getchar();
	return ch;
}
void put(int x) {
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

struct node {char c1, c2;} g[N];
char ss[N]; int n, q;

bool checkl(int mid) {
	int id = mid; char cc = ss[mid];
	for(int i = 1; i <= q; i++) {
		if(g[i].c1 == cc) {
			if(g[i].c2 == 'L') id--;
			else id++;
			if(id <= 0) return 1;
			if(id > n) return 0;
			cc = ss[id];
		}
	} return 0;
}

bool checkr(int mid) {
	int id = mid; char cc = ss[mid];
	for(int i = 1; i <= q; i++) {
		if(g[i].c1 == cc) {
			if(g[i].c2 == 'L') id--;
			else id++;
			if(id > n) return 1;
			if(id <= 0) return 0;
			cc = ss[id];
		}
	} return 0;
}

int main() {
	n = read(), q = read();
	scanf("%s", ss + 1);
	for(int i = 1; i <= q; i++) g[i].c1 = getc(), g[i].c2 = getc();
	int l = 1, r = n, h1 = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(checkl(mid)) l = mid + 1, h1 = mid;
		else r = mid - 1;
	} l = 1, r = n; int h2 = n + 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(checkr(mid)) r = mid - 1, h2 = mid;
		else l = mid + 1;
	} h1++, h2--;
	if(h1 > h2) puts("0");
	else put(h2 - h1 + 1), puts("");
	return 0;
}
