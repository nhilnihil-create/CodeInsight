#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long N;
    scanf("%ld", &N);
    for(long n = 1; n <=3500; n++){
        for(long h = 1; h <= 3500; h++){
            if(4 * n * h - N * n - N * h <= 0){
                continue;
            }
            if((N * n * h) % (4 * n * h - N * n - N * h)  == 0){
                long w = (N * n * h) / (4 * n * h - N * n - N * h);
                printf("%ld %ld %ld", n, h, w);
                return 0;
            }
        }
    }
    
    return 0;
}
