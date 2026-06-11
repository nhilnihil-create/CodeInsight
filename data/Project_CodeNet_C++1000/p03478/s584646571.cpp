#include <stdio.h>

int digits(int i){
	int tensOfThousands = i / 10000;
	int thousands = (i % 10000) / 1000;
	int hundreds = (i % 10000 % 1000) / 100;
	int tens = (i % 10000 % 1000 % 100) / 10;
	int ones = i % 10000 % 1000 % 100 % 10;
	int check = tensOfThousands + thousands + hundreds + tens + ones;
	
	return check;
}

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	
	int sum = 0;
	for(int i = a; i <= n; i++){
		if(digits(i) >= a && digits(i) <= b){
			sum += i;
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}