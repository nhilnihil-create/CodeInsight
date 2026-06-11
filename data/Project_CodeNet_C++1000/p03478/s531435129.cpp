#include <stdio.h>

int main() {
	int n, a,b;
	scanf("%d %d %d", &n, &a,&b);
	int sum = 0;
	for(int i = 1; i <= n ; i++){
		int temp = i, total = 0;
		while (temp > 0){
			total += temp % 10;
			temp /= 10;
		}
		if(total >= a && total <= b){
			sum += i;
		}
	}
	printf("%d\n", sum);
	
	return 0;
}
