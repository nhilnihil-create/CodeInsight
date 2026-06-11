#include <stdio.h>
int main()
{
	int apple, pieces, applepie;
	
	scanf("%d %d",&apple, &pieces);
	
	applepie=(apple*3 + pieces) / 2;
 
	printf("%d\n", applepie);
 
	return 0;
}