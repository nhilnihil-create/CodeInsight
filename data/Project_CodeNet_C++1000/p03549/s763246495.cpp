#include<cstdio>

int main(){
    unsigned N, M;
    scanf("%u %u", &N, &M);
    printf("%u\n", (1<<M)*(1800*M + 100*N));
	return 0;
}