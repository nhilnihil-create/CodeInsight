#include <stdio.h>

int main () {
	
	int N;
	int K;
	
	scanf ("%d %d", &N, &K);
	char str [N];
	scanf ("%s", &str);
	str [K-1]+=32;
	printf ("%s", str);
	
	return 0;
}