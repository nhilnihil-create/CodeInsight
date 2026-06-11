#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    long double p = 0;

    for(long long i = 1; i <= n; i++){
        if(i >= k){
            p += (long double) 1/(long double) n;
            continue;
        }

        long double cnt = 1;

        long long start = i;

        while(start < k){
            start *= 2;
            cnt *= 2;
        }

        p += ((long double) 1/(long double) n) / cnt;
    }

    printf("%.10Lf\n", p);
    return 0;
}