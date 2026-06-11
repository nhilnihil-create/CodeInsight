#include <bits/stdc++.h>
using namespace std;
char s[100005];
int n;
bool chk(int k) {
	bool ok = 1;
	for (int i = 0; i + 1 < n; ++ i) {
		if (s[i] != s[i + 1]) {
			ok &= (i + 1) >= k || (n - i - 1) >= k;
		}
	}
	return ok;
}
int main() {
	scanf("%s", s);
	n = strlen(s);
	int lb = (n + 1) / 2, rb = n;
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (chk(md)) lb = md;
		else rb = md - 1;
	}
	printf("%d\n", lb);
	return 0;
}