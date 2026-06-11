#include<stdio.h>
int main(){
	int apple;
	int Papple;
	int total;
	int pie;
	scanf("%d %d", &apple, &Papple);
	total = 3*apple + Papple;
	pie = total / 2;
	printf("%d", pie);
	return 0;
}