#include<stdio.h>

int main(){
	int tc, n;
	scanf("%d %d", &tc, &n);
	char word[tc+2];
	scanf("%s", word);
	word[n-1]+=32;
	printf("%s\n", word);
	return 0;
}