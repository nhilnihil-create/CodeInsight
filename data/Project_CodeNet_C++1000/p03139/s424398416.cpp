#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,A,B;
    int Max=0, Min=0;
    scanf("%d%d%d", &N, &A, &B);
    Max = min(A,B);
    if(A+B>=N){
        Min = A+B-N;
    }
    printf("%d %d" , Max, Min);
    return 0;
}