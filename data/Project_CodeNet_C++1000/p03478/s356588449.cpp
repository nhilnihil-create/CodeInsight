#include <stdio.h>

int main (){
	int t, a, b;
	scanf("%d %d %d", &t, &a, &b);
	int sum =0;
	for (int i=1; i<=t; i++){
		int digitsum=0;
		int temp =i;
		while (temp !=0){
			digitsum = digitsum +temp%10;
			temp/=10;
		}
		if (digitsum >=a && digitsum <=b){
			sum += i;
		}
	}
	printf("%d\n", sum);
	return 0;
}