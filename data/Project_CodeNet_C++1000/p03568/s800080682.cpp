#include<iostream>
using namespace std;
int N;
int A[10];
int main(){
    scanf("%d", &N);
    int all = 1, bad = 1;
    for(int i = 0; i < N; ++i){
        scanf("%d", A + i);
        all *= 3;
        if(A[i] % 2 == 0) bad *= 2;
}
printf("%d\n", all - bad); return 0;
}
