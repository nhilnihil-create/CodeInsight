#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int nCount = 100000;
    for(int a = 0; a < 6; a++){  //1
        for(int b = 0; b < 3; b++){  //6
            for(int c = 0; c < 4; c++){  //9
                for(int d = 0; d < 6; d++){  //36 (36 * 6 = 216)
                    for(int e = 0; e < 8; e++){  //81 (81 * 8 = 216 * 3)
                        for(int f = 0; f < 6; f++){  //216 (216 * 6 = 729) 
                            for(int g = 0; g < 9; g++){  //729
                                for(int h = 0; h < 6; h++){  //1296
                                    for(int i = 0; i < 9; i++){  //6561
                                        for(int j = 0; j < 6; j++){  //7776
                                            for(int k = 0; k < 2; k++){  //59049
                                                for(int l = 0; l < 3; l++){  //46656
                                                    if(a+b*6+c*9+d*36+e*81+f*216+g*729+h*1296+i*6561+j*7776+k*59049+l*46656 == n){
                                                        nCount = min(nCount, a+b+c+d+e+f+g+h+i+j+k+l);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("%d", nCount);
    return 0;
}
