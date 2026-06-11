#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long d, n;
    cin >> d >> n;

    if(d == 0){
        if(n <= 99){
            printf("%lld\n", n);
        }
        else{
            printf("101\n");
        }
    }
    else if(d == 1){
        if(n <= 99){
            printf("%lld\n", 100*n);
        }
        else{
            printf("10100\n");
        }
        
        
    }
    else if(d == 2){
        if(n <= 99){
            printf("%lld\n", 10000*n);
        }
        else{
            printf("1010000\n");
        }
        
    }

    return 0;
}