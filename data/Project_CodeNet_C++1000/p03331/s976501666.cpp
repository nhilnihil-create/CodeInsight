#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	int digit_sum = 0;
	while(n > 0){
		digit_sum += n % 10;
		n /= 10;
	}
	if(digit_sum == 1){
		digit_sum = 10;
	}
	printf("%d\n", digit_sum);
	return 0;
}