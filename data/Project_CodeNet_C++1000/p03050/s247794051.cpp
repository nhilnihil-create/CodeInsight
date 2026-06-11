#include <stdio.h>

int main(void){
    unsigned long long int n; scanf("%llu", &n);
    // n / x = n % x = a とすると n = a * (x + 1) : ただし, x > a
    unsigned long long int res = 0;
    for(unsigned long long int t = 1; t * t <= n; ++t) if(!(n % t)){
        unsigned long long int s = n / t;
        if(s - 1 > t) res += s - 1;
        if(s != t){
            if(t - 1 > s) res += t - 1;
        }
    }
    printf("%llu\n", res);
    return 0;
}