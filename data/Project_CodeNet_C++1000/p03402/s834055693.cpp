#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>

typedef long long ll;
using namespace std;

int main(void){
  int w,b,i,j,x,y;
  static bool grid[100][100];

  cin>>w>>b;
  for(i=0;i<100;i++){
    for(j=0;j<50;j++){
      grid[j][i]=0;
    }
    for(j=50;j<100;j++){
      grid[j][i]=1;
    }
  }

  x=0,y=0;
  for(i=0;i<b-1;i++){
    grid[y][x]=1;
    x=x+2;
    if(x>=100){
      x=0;
      y=y+2;
    }
  }
  x=0,y=51;
  for(i=0;i<w-1;i++){
    grid[y][x]=0;
    x=x+2;
    if(x>=100){
      x=0;
      y=y+2;
    }
  }

  printf("100 100\n");
  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      if(grid[i][j]){
        printf("#");
      }
      else{
        printf(".");
      }
    }
    printf("\n");
  }

  return 0;
}
