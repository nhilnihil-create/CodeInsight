#include <stdio.h>
int main(){
	int N, hurufK;
	
	scanf("%d %d", &N, &hurufK);
	char kata[N+1];
	scanf("%s", &kata);
	
	kata[hurufK-1] = kata[hurufK-1]+32;
	
	printf("%s\n", kata);
	
	
	return 0;
}