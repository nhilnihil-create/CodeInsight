#include <stdio.h>
#include <string.h>
#define M 1000000007

char s[100001], ts;
int a[3][3], c = 1;

int add(int x, int y)
{
	int t = x + y;
	if(t >= M) t -= M;
	return t;
}

int main() 
{
	int i, i1, i2;
	int s0 = 0, s1 = 0, s2 = 0, f;
	
	scanf("%s", s);
	i = strlen(s) - 1;
	for(; i >= 0; i--){
		for(i1 = 0; i1 < 3; i1++){
			for(i2 = 0; i2 < 3; i2++) a[i1][i2] = 0;
		}
		ts = s[i], f = (ts == '?');
		if(f || ts == 'A'){
			a[0][0] = add(s0, s1);
			a[0][1] = s1;
			a[0][2] = s2;
		}
		if(f || ts == 'B'){
			a[1][0] = s0;
			a[1][1] = add(s1, s2);
			a[1][2] = s2;
		}
		if(f || ts == 'C'){
			a[2][0] = s0;
			a[2][1] = s1;
			a[2][2] = add(s2, c);
		}
		if(f) c = add(add(c, c), c);
		s0 = add(a[2][0], add(a[1][0], a[0][0]));
		s1 = add(a[2][1], add(a[1][1], a[0][1]));
		s2 = add(a[2][2], add(a[1][2], a[0][2]));
	}
	printf("%d\n", s0);
			
	return 0;
}