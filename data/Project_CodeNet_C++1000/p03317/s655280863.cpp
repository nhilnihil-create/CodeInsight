#include<cstdio>

int main(){
    unsigned N, K;
    scanf("%u %u", &N, &K);
    printf("%u\n", (N-2)/(K-1) + 1);
	return 0;
}