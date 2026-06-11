#include <bits/stdc++.h>

using namespace std;

const int N = 200000;

int n;
int a[N + 1];
int pos[N + 1];
int f[N + 1];
int si[N + 1];

int find(int x) {
	return f[x] = (f[x] == x ? x : find(f[x]));
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) pos[a[i]] = i;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= n; i++) si[i] = 1;
	for(int i = 1; i < n; i++)
		if(pos[i] < pos[i + 1])
			 si[find(i + 1)] += si[find(i)], f[i] = f[i + 1];
	int res = n;
	for(int i = 1; i <= n; i++) res = min(res, n - si[find(i)]);
	printf("%d\n", res);
	return 0;
}