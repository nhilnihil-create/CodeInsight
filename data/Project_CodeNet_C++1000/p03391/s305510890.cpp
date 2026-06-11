#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n;
    scanf("%ld", &n);
    long iMin = 2000000000;
    long iSum = 0;
    bool bSame = true;
    for(long i = 0; i < n; i++){
        long a,b;
        scanf("%ld %ld", &a, &b);
        iSum += a;
        if(a > b){
            bSame = false;
            iMin = min(iMin, b);
        }
    }
    if(bSame){
        printf("0");
    } else {
        printf("%ld", iSum - iMin);
    }
    return 0;
}
