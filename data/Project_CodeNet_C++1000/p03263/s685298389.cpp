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
  int h, w, i, j;
  vector<vector<int> > a;
  vector<vector<int> > out;
  cin >> h >> w;
  
  a.resize(h,vector<int>(w));
  out.clear();

  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin >> a[i][j];
    }
  }

  int n = 0;

  for(i=0;i<h;i++){
    for(j=0;j<w-1;j++){
      if(a[i][j]%2==1){
        //printf("%d %d %d %d\n",i,j,i,j+1);
        out.push_back({i,j,i,j+1});
        ++a[i][j+1];
        ++n;
      }
    }
  }

   for(i=0;i<h-1;i++){
    if(a[i][w-1]%2==1){
      //printf("%d %d %d %d\n",i,w-1,i+1,w-1);
      out.push_back({i,w-1,i+1,w-1});
      ++a[i+1][w-1];
      ++n;
    }
  }

  printf("%d\n",n);

  for(i=0;i<out.size();i++){
    printf("%d %d %d %d\n",out[i][0]+1,out[i][1]+1,out[i][2]+1,out[i][3]+1);
  }

  return 0;
}
