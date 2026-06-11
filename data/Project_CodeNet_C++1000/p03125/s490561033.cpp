#include <stdio.h>
int main (){
	int c, d;
	scanf ("%d %d", &c, &d);
	if (c % d == 0 || d % c == 0){
		printf ("%d", c + d);
	}else{
		printf ("%d", d - c);
	}
	return 0;
}