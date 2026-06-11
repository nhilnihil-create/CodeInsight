#include <bits/stdc++.h>
using namespace std;

int digits[25];
long long S(long long k){
    long long res = 0;
    while(k){
        res += k%10;
        k /= 10;
    }
    return res;
}

long long Pow10[20];

int main(){
    int K;
    scanf("%d", &K);

    long long temp = 1;
    printf("%lld\n", temp);
    Pow10[0] = 1;
    for(int i = 1; i < 19; i ++){
        Pow10[i] = 10*Pow10[i-1];
    }
    K --;
    while(K){
        long long next1 = temp;
        double bestVal = 1e308;
        for(int i = 0; i < 18; i ++){
            long long nextTemp = temp+Pow10[i];
            double val1 = (double)nextTemp/S(nextTemp);
            if(bestVal > val1){
                bestVal = val1;
                next1 = nextTemp;
            }
        }

        K --;
        printf("%lld\n", next1);
        temp = next1;
    }

    return 0;
}
