#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long long N, K, t, s;
    scanf("%lld %lld", &N, &K);
    if( K % 2 ){
        t = N / K;
        printf("%lld\n" , t * t * t);
    }else{
        t = N / K;
        s = (N + K / 2) / K ;
        printf("%lld\n" , t * t * t + s * s * s);
    }
    return 0;
}
