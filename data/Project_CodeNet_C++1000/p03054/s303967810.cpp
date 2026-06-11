#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int A, B, n, X, Y;
int a[maxn], b[maxn];
char s[maxn], t[maxn];

bool check(int N, int x) {
	int l = 1, r = N;
	for (int i = n; i >= 1; --i) {
		if(b[i] == 1) l = max(1, l - 1);
		if(b[i] == -1) r = min(N, r + 1);
		if(a[i] == 1) --r;
		if(a[i] == -1) ++l;
		if(l > r) return 0;
	}
	return (x >= l && x <= r);
}

int main() {
	scanf("%d%d%d%d%d", &A, &B, &n, &X, &Y);
	scanf("%s%s", s + 1, t + 1);
	int fl = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = b[i] = 0;
		if(s[i] == 'U') a[i] = -1;
		if(s[i] == 'D') a[i] = 1;
		if(t[i] == 'U') b[i] = -1;
		if(t[i] == 'D') b[i] = 1;
	}
	if(!check(A, X)) fl = 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = b[i] = 0;
		if(s[i] == 'L') a[i] = -1;
		if(s[i] == 'R') a[i] = 1;
		if(t[i] == 'L') b[i] = -1;
		if(t[i] == 'R') b[i] = 1;
	}
	if(!check(B, Y)) fl = 1;
	if(fl) printf("NO\n");
	else printf("YES\n");
	return 0;
}