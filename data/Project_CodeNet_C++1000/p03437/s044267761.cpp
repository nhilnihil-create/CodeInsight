#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	long long i, no, X, Y;
	scanf("%lld %lld", &X, &Y);

	no = 1000000000000000000 / X;

	if ( X==Y ||
		(X>Y && !(X%Y)) ){printf("-1"); return 0;}
	
	for(i=2;i<=no;i++){	
		if ((X * i) % Y){ 
			printf("\n%lld",X*i); return 0;
		}
	}
	printf("\n-1");
	return 0;
}