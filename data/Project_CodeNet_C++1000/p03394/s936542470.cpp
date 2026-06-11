#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
  
    if(n == 3){
        printf("5 9 16");
        return 0;
    }
    int nNum = n / 8;
    for(int i = 0; i < nNum; i++){
        int k = 12 * i;
        printf("%d %d %d %d %d %d %d %d ", k+2, k+3, k+4, k+6, k+8, k+9, k+10, k+12);
    }
    
    int nMax = nNum * 12;
    switch(n % 8){
      case 0:
        break;
      case 1:
        printf("%d", nMax+6);
        break;
      case 2:
        printf("%d %d", nMax+6, nMax+12);
        break;      
      case 3:
        printf("%d %d %d", nMax+2, nMax+4, nMax+6);
        break;
      case 4:
        printf("%d %d %d %d", nMax+2, nMax+3, nMax+4, nMax+9);
        break;
      case 5:
        printf("%d %d %d %d %d", nMax+2, nMax+3, nMax+4, nMax+6, nMax+9);
        break;
      case 6:
        printf("%d %d %d %d %d %d", nMax+2, nMax+3, nMax+4, nMax+8, nMax+9, nMax+10);
        break;
      case 7:
        printf("%d %d %d %d %d %d %d", nMax+2, nMax+3, nMax+4, nMax+6, nMax+8, nMax+9, nMax+10);
        break; 
      default:
        return 1;
    }
    
    return 0;
}
