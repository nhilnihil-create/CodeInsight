#include<cstdio>
using ull = unsigned long long;

int main(){
	ull A, B;
	scanf("%llu %llu", &A, &B);
	ull begin = A + 1 >> 1 << 1;
	begin += B + 1 - begin >> 2 << 2;
	ull ans = A & 1 ? A : 0;
	for (ull i = begin; i <= B; ++i){
		ans ^= i;
	}
	printf("%llu\n", ans);
	return 0;
}