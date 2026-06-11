#include<stdio.h>

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int sum = 0;
	for(int i = 1; i <= n; i++){
		int numSum = 0;
		int temp = i;
		while(temp > 0){
			numSum = numSum + (temp % 10);
			temp = temp / 10;
		}
		if(numSum >= a && numSum <= b){
			sum += i;
		}
	}
	printf("%d", sum);
	return 0;
}