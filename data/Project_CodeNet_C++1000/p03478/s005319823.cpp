#include <stdio.h>

int main(){
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);
	int ans = 0;
	for(int i = 1; i <= N; i++){
		int temp = i;
		int total = 0;
		
		while(temp > 0){
			total += temp % 10;
			temp /= 10;
		}
		if(total >= A && total <= B){
			ans += i;
		}
	}
	printf("%d\n", ans);
	return 0;
}