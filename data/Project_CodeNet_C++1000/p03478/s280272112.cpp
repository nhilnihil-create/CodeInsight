#include <stdio.h>
#include <string.h>

int digit(int i){
	int sum = 0;
	while(i > 0){
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	
	int sum = 0;
	
	for(int i = 1; i <= n; i++){
		if(digit(i) >= a && digit(i) <= b){
		sum += i;
		}	
	}
	printf("%d\n", sum);
	return 0;
}