#include <bits/stdc++.h>
using namespace std;

char s[100005];
int c[3];

int main() {
	scanf("%s", s);
	for (char* p = s; *p; c[*(p++) - 'a']++);
	sort(c, c + 3);
	puts((c[2] - c[0] <= 1) ? "YES" : "NO");
	return 0;
}
