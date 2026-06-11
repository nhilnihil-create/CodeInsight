#include<stdio.h>
int main(){
	int apel,potongan;
	scanf("%d %d", &apel, &potongan);
	int total=((apel*3)+potongan)/2;
	printf("%d\n", total);
	return 0;
}