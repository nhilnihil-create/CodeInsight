#include <bits/stdc++.h>

#define N 1000010 

using namespace std;

int Log[N];

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
	int x = 0, f = 1;
	char c = nc();
	while (c < 48) {
		if (c == '-')
			f = -1;
		c = nc();
	}
	while (c > 47) {
		x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
	}
	return x * f;
}

int bin[21];

int a[20];

struct Node {
	int x, y, z;
}e[100];

int main() {
	int n = rd();
	n -- ;
	bin[0] = 1;
	for (int i = 1; i <= 20; i ++ ) {
		bin[i] = bin[i - 1] << 1;
	}
	int k = 0;
	int m = n;
	bool flag = false;
	while (m) {
		k ++ ;
		if (m % 2 == 0) {
			flag = true;
		}
		m /= 2;
	}
	int tot = 0;
	if (!flag) {
		cout << k + 1 << ' ' ;
		for (int i = 1; i <= k; i ++ ) {
			// i -> i + 1
			tot ++ ;
			e[tot].x = i, e[tot].y = i + 1, e[tot].z = bin[i - 1];
			tot ++ ;
			e[tot].x = i, e[tot].y = i + 1, e[tot].z = 0;
		}
		cout << tot << endl ;
		for (int i = 1; i <= tot; i ++ ) {
			printf("%d %d %d\n", e[i].x, e[i].y, e[i].z);
		}
		return 0;
	}
	// puts("Fuck");
	cout << k << ' ' ;
	for (int i = 1; i < k; i ++ ) {
		tot ++ ;
		e[tot].x = i, e[tot].y = i + 1, e[tot].z = bin[k - i - 1];
		tot ++ ;
		e[tot].x = i, e[tot].y = i + 1, e[tot].z = 0;
	}
	int cnt = 0;
	for (int i = 0; i <= 20; i ++ ) {
		if (n & bin[i]) {
			a[ ++ cnt] = i;
		}
	}
	int pre = bin[a[cnt]];
	for (int i = cnt - 1; i; i -- ) {
		tot ++ ;
		e[tot].x = 1, e[tot].y = k - a[i], e[tot].z = pre;
		pre += bin[a[i]];
	}
	tot ++ ;
	e[tot].x = 1, e[tot].y = k, e[tot].z = n;
	cout << tot << endl ;
	for (int i = 1; i <= tot; i ++ ) {
		printf("%d %d %d\n", e[i].x, e[i].y, e[i].z);
	}
	return 0;
}