#include<cstdio>
#include<algorithm>
using namespace std;
char a[200010];
char b[200010];
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int st, en;
	scanf("%d %d", &st, &en);
	for (int i = 0; i < k; i++)
		scanf(" %1c", &a[i]);
	for (int i = 0; i < k; i++)
		scanf(" %1c", &b[i]);
	int ch = en;
	for (int i = 0; i < k; i++) {
		if (a[i] == 'R')ch++;
		if (ch > m) {
			puts("NO");
			return 0;
		}
		if (b[i] == 'L') {
			if(ch>1)
				ch--;
		}
	}
	ch = en;
	for (int i = 0; i < k; i++) {
		if (a[i] == 'L')ch--;
		if (ch==0) {
			puts("NO");
			return 0;
		}
		if (b[i] == 'R') {
			if (ch<m)
				ch++;
		}
	}
	ch = st;
	for (int i = 0; i < k; i++) {
		if (a[i] == 'U')ch--;
		if (ch == 0) {
			puts("NO");
			return 0;
		}
		if (b[i] == 'D') {
			if (ch < n)
				ch++;
		}
	}
	ch = st;
	for (int i = 0; i < k; i++) {
		if (a[i] == 'D')ch++;
		if (ch > n) {
			puts("NO");
			return 0;
		}
		if (b[i] == 'U') {
			if (ch > 1)ch--;
		}
	}
	puts("YES");
}