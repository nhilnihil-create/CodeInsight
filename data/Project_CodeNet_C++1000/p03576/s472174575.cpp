#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n,k;
    scanf("%ld %ld", &n, &k);
    vector<long> vix(n * n),viy(n * n);
    for(long i = 0; i < n; i++){
        long x,y;
        scanf("%ld %ld", &x, &y);
        for(long j = 0 ; j < n; j++){
            vix[n * i + j] = x;
            viy[n * j + i] = y;
        }
    }
    
    long SAns = LONG_MAX;
    for(long i = 0; i < n * n - 1; i++){
        for(long j = i + 1; j < n * n; j++){
            long nCount = 0;
            for(long k = 0; k < n; k++){
                if((vix[i] - vix[(n+1) * k]) * (vix[j] - vix[(n+1) * k]) > 0){
                    continue;
                }
                if((viy[i] - viy[(n+1) * k]) * (viy[j] - viy[(n+1) * k]) > 0){
                    continue;
                }
                nCount++;
            }
            if(nCount >= k){
                long STmp = abs((vix[i] - vix[j]) * (viy[i] - viy[j]));
                if(STmp < SAns){
                    SAns = STmp;
                }
            }
        }
    }
    
    printf("%ld", SAns);
    return 0;
}
