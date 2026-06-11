#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int lMax = 0;
    int lSum = 0;
    for (int i = 0; i < n; i++){
        int l;
        scanf("%d", &l);
        lSum += l;
        if(l > lMax){
            lMax = l;
        }
    }
  
    if(lSum <= lMax * 2){
        printf("No");
    } else {
        printf("Yes");
    }
      
    return 0;
}
