#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> viHeight(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &viHeight[i]);
    }
    int nCount = 0;
    while(true){
      int nSegmentCount = 0;
      bool bSegment = false;
      for(int i = 0; i < n; i++){
          if(viHeight[i] == 0){
              bSegment = false;
          } else {
              if(!bSegment){
                  nSegmentCount++;
                  bSegment = true;
              }
              viHeight[i] -= 1;
          }
          
      }
      nCount += nSegmentCount;
      bool bAllZero = true;
      for (int i = 0; i < n; i++){
          if(viHeight[i] > 0){
              bAllZero = false;
              break;
          }
      }
      if(bAllZero){
          break;
      }
    }
    
    printf("%d", nCount);

    return 0;
}
