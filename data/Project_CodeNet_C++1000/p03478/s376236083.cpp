#include<stdio.h>

int main(){
	int N,A,B;
	scanf("%d %d %d",&N,&A,&B);
	int sum = 0;
	for(int i= 1;i<=N;i++){
		int digitSum = 0;
		int temp = i;
		while (temp != 0){
			digitSum = digitSum + temp % 10;
			temp /= 10;
		}
		if (digitSum >= A && digitSum <= B){
			sum += i;
		}
	}
	printf("%d\n",sum);
	return 0;
}