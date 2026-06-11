#include <bits/stdc++.h>
using namespace std;

long long A[100005];

int K;

bool doesItWork(long long num){
    long long temp = num;
    for(int i = 0; i < K; i ++){
        temp = temp/A[i]*A[i];
    }
    return temp == 2;
}

int main(){
    scanf("%d", &K);

    for(int i = 0; i < K; i ++){
        scanf("%lld", &A[i]);
    }

    long long num = 2;
    for(int i = K-1; i >= 0; i --){
        long long temp = 1+(num-1)/A[i];
        num = temp*A[i];
    }

    long long num2 = 2;
    for(int i = K-1; i >= 0; i --){
        long long temp = 1+(num2-1)/A[i];
        num2 = (temp+1)*A[i]-1;
    }

    if(doesItWork(num)){
        printf("%lld ", num);

        long long lo = num;
        long long hi = 1LL << 61;
        while(lo < hi){
            long long mid = (lo+hi+1)/2;
            if(doesItWork(mid)){
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
        printf("%lld", lo);
    }else{
        printf("-1");
    }
    return 0;
}
