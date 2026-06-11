#include<cstdio>
#include<cstdlib>

int main(){
    unsigned N;
    scanf("%u", &N);
    int A[N+2];
    A[0] = A[N+1] = 0;
    scanf("%d %d", A+1, A+2);
    unsigned answer = abs(A[2]);
    for(int i = 3; i <= N; ++i){
        scanf("%d", A + i);
        answer += abs(A[i] - A[i-1]);
    }
    answer += abs(A[N+1] - A[N]);
    printf("%u\n", answer);
    for (size_t i = 1; i < N; i++){
        printf("%u\n", answer = answer + abs(A[i] - A[i-1]) + abs(A[i] - A[i+2]) - abs(A[i+1] - A[i-1]) - abs(A[i+1] - A[i+2]));
    }
	return 0;
}