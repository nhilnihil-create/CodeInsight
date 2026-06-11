#include<cstdio>

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	if(n + 1 >= a + b && (long long)a * (long long)b >= n) {
		int m = n;
		for(int i=b;i>0;i--) {
			printf("%d\n", i);
			int from = b+1 > m-a+2 ? b+1 : m-a+2;
			for(int j=from;j<=m;j++) {
				printf("%d\n", j);
			}
			if(m >= from) m = from-1;
		}
	} else {
		printf("-1\n");
	}
	return 0;
}
