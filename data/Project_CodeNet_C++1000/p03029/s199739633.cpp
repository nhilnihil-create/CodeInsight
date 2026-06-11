#include <stdio.h>

int main () {

int x;
int y;
scanf("%d%d", &x, &y);

	if(x+y<0) {
		printf("%d", x+y);
	}
	else {
		printf("%d", (x*3+y)/2);
	}

}