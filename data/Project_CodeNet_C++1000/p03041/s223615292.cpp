#include <stdio.h>

int main(){
	
	int num;
	int aci;
	char total[52];
	
	scanf("%d %d", &num, &aci);
	scanf("%s", &total);
	
	total[aci - 1] = total[aci - 1] + 32;
	
	printf("%s", total);
	
	return 0;
}