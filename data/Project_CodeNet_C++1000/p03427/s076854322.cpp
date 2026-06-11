#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

long long n;
int num_digits;
int num_nine;
int first_digit;

int main(){
	scanf("%lld", &n);
	while(n >= 10){
		num_digits++;
		num_nine += (n % 10 == 9);
		n /= 10;
	}
	first_digit = n;
	if(num_nine == num_digits){
		printf("%d\n", first_digit + 9 * num_digits);
	}else{
		printf("%d\n", first_digit - 1 + 9 * num_digits);
	}
	return 0;
}