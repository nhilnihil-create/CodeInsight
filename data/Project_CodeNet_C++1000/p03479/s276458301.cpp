#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long int x,y;
    scanf("%ld %ld", &x, &y);
    long int n = y / x;
    int nCount = 1;
    while(n >= 2){
        n /= 2;
        nCount++;
    }
    printf("%d", nCount);
    return 0;
}
