#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    unsigned X, Y, Z, K;
    scanf("%u %u %u %u", &X, &Y, &Z, &K);
    ull A[X];
    for(int i = 0; i < X; ++i){
        scanf("%llu", A + i);
    }
    ull B[Y];
    for(int i = 0; i < Y; ++i){
        scanf("%llu", B + i);
    }
    ull C[Z];
    for(int i = 0; i < Z; ++i){
        scanf("%llu", C + i);
    }
    if(X > K){
        nth_element(A, A + K - 1, A + X, greater<ull>());
        X = K;
    }
    if(Y > K){
        nth_element(B, B + K - 1, B + Y, greater<ull>());
        Y = K;
    }
    if(Z > K){
        nth_element(C, C + K - 1, C + Z, greater<ull>());
        Z = K;
    }
    ull ab[X*Y];
    for (size_t i = 0; i < X; i++){
        for (size_t j = 0; j < Y; j++){
            ab[i*Y + j] = A[i] + B[j];
        }
    }
    if(X*Y > K){
        nth_element(ab, ab + K - 1, ab + X*Y, greater<ull>());
    }
    unsigned product = min(X*Y, K);
    ull answer[product*Z];
    for (size_t i = 0; i < Z; i++){
        for (size_t j = 0; j < product; j++){
            answer[i*product + j] = C[i] + ab[j];
        }
    }
    partial_sort(answer, answer + K, answer + product*Z, greater<ull>());
    for (size_t i = 0; i < K; i++){
        printf("%llu\n", answer[i]);
    }
	return 0;
}