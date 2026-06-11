#include <stdio.h>
#include <string.h>

int Sum(int i){
	int s = 0;
	while(i > 0){
		s += i%10;
		i/=10;
	}
	return s;
}


int main() {
	int n, a ,b;
	scanf("%d %d %d", &n, &a, &b);
	int s = 0;
	for(int i = 1; i <= n; i++){
		if(Sum(i) >= a&&Sum(i) <= b){
			s+=i;
		}
	}
	printf("%d", s);
	
	return 0;
}