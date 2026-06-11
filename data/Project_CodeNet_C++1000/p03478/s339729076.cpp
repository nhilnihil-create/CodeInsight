#include <stdio.h>

int main(){
	int n;
	int a, b;
	scanf("%d %d %d", &n, &a, &b);
	int sum =0;
	
	for (int i=1; i<=n; i++){
		int digitSum=0;
		int temp=i;
		while (temp!=0){
			digitSum = digitSum + temp%10;
			temp/= 10;
		}
		if (digitSum >=a && digitSum <= b){
			sum += i;
		}
			
	}
	printf("%d\n", sum);
	return 0;
}