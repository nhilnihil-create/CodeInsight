#include <stdio.h>
int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	char str[n+1];
	scanf("%s",&str);
	str[k-1] += 32;
	printf("%s",str);
	return 0;
}