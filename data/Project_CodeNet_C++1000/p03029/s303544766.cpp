#include <stdio.h>
#include <string.h>

int main(){
	int A, P, Slice, Pie;
	scanf("%d %d", &A, &P);
	Slice = 3*A + P;
	Pie = Slice / 2;
	printf("%d", Pie);
	
	return 0;
}