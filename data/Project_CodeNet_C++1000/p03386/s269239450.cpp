#include<stdio.h>
int min(int x, int y)
{
	if(x<y) return x;
	return y;
}
int max(int x, int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	int a,b,c,i,j,k;
	scanf("%d %d %d", &a, &b, &k);
	for(i=a; i<=min(b,a+k-1); i++)
		printf("%d\n", i);
	for(i=max(a+k, b-k+1); i<=b; i++)
		printf("%d\n", i);
	return 0;
}