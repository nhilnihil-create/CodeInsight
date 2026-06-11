#include <iostream>
using namespace std;
int main()
{
  int n,y;
  cin >> n >> y;
  for(int i=0;i<=2000;i++){
    for(int j=0;j<=2000;j++){
      int z = 10000*i + 5000*j;
      int k = (y - z)/1000;
      if(k >= 0){
        if(i+j+k == n){
          printf("%d %d %d\n",i,j,k);
          return 0;
        }
      }
    }
  }
  printf("-1 -1 -1\n");
  return 0;
}