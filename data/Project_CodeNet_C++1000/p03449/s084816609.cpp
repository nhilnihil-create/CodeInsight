#include<cstdio>
const static int MAX_N = 100;
unsigned A[2][MAX_N];

int main(){
    unsigned N;
    scanf("%u", &N);
    for (size_t i = 0; i < N; i++) scanf("%u", &A[0][i]);
    unsigned answer = A[0][0];
    for (size_t i = 0; i < N; i++){
        scanf("%u", &A[1][i]);
        answer += A[1][i];
    }
    unsigned last = answer;
    for (size_t i = 1; i < N; i++){
        last = last + A[0][i] - A[1][i-1];
        if(answer < last)answer = last;
    }
    printf("%u\n", answer);
	return 0;
}