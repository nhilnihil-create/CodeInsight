#include <cstdio>
#include <iostream>

using namespace std;

int n, m, len, sx, sy;

char s[200010], t[200010];

int main () {
	scanf ("%d%d%d", &n, &m, &len);
	scanf ("%d%d", &sx, &sy);
	scanf ("%s", s + 1);
	scanf ("%s", t + 1);
	
	int l = 0, r = n + 1;
	
	for (int i = len; i >= 1; --i) {
		if (t[i] == 'U' && r <= n) ++r;
		if (t[i] == 'D' && l >= 1) --l;
		if (s[i] == 'U') ++l;
		if (s[i] == 'D') --r;
		if (l >= r - 1) { printf ("NO\n"); return 0; }
	}
	
	if (l >= sx || r <= sx) { printf ("NO\n"); return 0; }
	
	l = 0, r = m + 1;
	
	for (int i = len; i >= 1; --i) {
		if (t[i] == 'L' && r <= m) ++r;
		if (t[i] == 'R' && l >= 1) --l;
		if (s[i] == 'L') ++l;
		if (s[i] == 'R') --r;
		if (l >= r - 1) { printf ("NO\n"); return 0; }
	}
	
	if (l >= sy || r <= sy) { printf ("NO\n"); return 0; }
	
	printf ("YES\n");
	
	return 0;
}