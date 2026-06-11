#include <stdio.h>
 
int main(){
	
int n, a, b, sum = 0;
	
scanf("%d %d %d", &n, &a, &b);

for (int i = 1; i <= n; i++){
	int k = 0;
	int temp = i;
		
    for (int j = 0; j < 5; j++){
		k += temp % 10;
		temp /= 10;
	}
		
    if (k >= a && k <= b){
	sum += i;
	}
}
 
printf("%d\n", sum);
 
	return 0;
}