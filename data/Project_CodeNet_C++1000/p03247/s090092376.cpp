#include <bits/stdc++.h>
using namespace std;

bool flag[5];
int x[1010],y[1010],d[50];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d",&x[i],&y[i]);
		flag[abs(x[i] + y[i]) % 2] = true;
	}
	if (flag[0] && flag[1]) { puts("-1"); return 0; }
	int m = 0;
	if (flag[0]) d[++m] = 1;
	for (int i = 30; i >= 0; i--) d[++m] = (1 << i);
	printf("%d\n" , m);
	for (int i = 1; i <= m; i++) printf("%d%s" , d[i] , i == m ? "\n" : " ");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (abs(x[i]) > abs(y[i])) {
				if (x[i] > 0) { x[i] -= d[j]; printf("R"); }
				else { x[i] += d[j]; printf("L"); }
			}
			else {
				if (y[i] > 0) { y[i] -= d[j]; printf("U"); }
				else { y[i] += d[j]; printf("D"); }
			}
		puts("");
	}
} 