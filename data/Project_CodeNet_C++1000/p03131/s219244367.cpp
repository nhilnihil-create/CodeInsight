#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long k, a, b;
    cin >> k >> a >> b;
    if(a < b){
        if(k <= a-1){
            printf("%lld\n", k+1);
            return 0;
        }
        else{
            if(b - a <= 1){
                printf("%lld\n", 1+k);
                return 0;
            }
            
            long long exchange = (k-(a-1))/2;
            long long clap = k-(a-1) - 2*exchange;
            printf("%lld\n", a+exchange*(b-a)+clap);
            return 0;
        }
    }
    else{
        printf("%lld\n", 1+k);

        return 0;
    }
}