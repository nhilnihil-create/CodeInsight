#include <stdio.h>

int main(){
	int a, p;
	scanf("%d %d", &a, &p);
	//a = 3p
	//pie = 2p
	int piece = a*3 + p;
	int ans = piece/2;
	printf("%d\n", ans);
	return 0;
}
