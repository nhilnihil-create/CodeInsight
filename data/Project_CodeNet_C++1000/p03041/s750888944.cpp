#include <stdio.h>
#include <string.h>
int main()
{
	char kata[55];
	int N,index;
	int K;
	
	scanf ("%d %d",&N,&K);
	getchar();
	scanf ("%s",&kata);
	getchar();
	
	kata[K-1] += 32;
	
	printf("%s",kata);
	
	return 0;
}