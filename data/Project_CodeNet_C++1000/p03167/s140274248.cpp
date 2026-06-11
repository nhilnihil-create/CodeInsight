#include <stdio.h>
#define N 1001
#define M 1000000007

int c[N][N] = {0};
char s[N][N];

int main()
{		
	int a, b, i, j, i0, j0, t;
	
	scanf("%d%d", &a, &b);
	for(i = 1; i <= a; i++) scanf("%s", s[i] + 1);
	for(i = 1, i0 = 0, c[0][1] = 1; i <= a; i0 = i++){
		for(j = 1, j0 = 0; j <= b; j0 = j++){
			if(s[i][j] == '#') continue;
			t = c[i][j0] + c[i0][j];
			if(t >= M) t -= M;
			c[i][j] = t;
		}
	}
	printf("%d\n", c[a][b]);
				
	return 0;
}