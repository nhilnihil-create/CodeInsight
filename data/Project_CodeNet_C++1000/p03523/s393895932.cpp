#include<cstdio>
#include<algorithm>
char p[100], q[100] = "AKIHABARA";
int main() {
	int i, pv = 0;
	scanf("%s", p);
	for (i = 0; q[i]; i++) {
		if (q[i] == p[pv]) {
			pv++;
		}
		else if(q[i] != 'A'){
			puts("NO");
			return 0;
		}
	}
	if (!p[pv])puts("YES");
	else puts("NO");
}