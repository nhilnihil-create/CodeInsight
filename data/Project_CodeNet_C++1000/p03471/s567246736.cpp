#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int N, Y, y, A, B, C;
  cin >> N >> Y;
  y = Y/1000;
  A = Y/10000;
  B = Y/5000;
  for(int i=0; i<=A; i++){
    for(int j=0; j<=B; j++){
      if(9*i+4*j == y-N && N-i-j>=0){
        C=N-i-j;
        printf("%i %i %i",i, j, C);
        return 0;
      }
    }
  }
  printf("-1 -1 -1");
  return 0;
}