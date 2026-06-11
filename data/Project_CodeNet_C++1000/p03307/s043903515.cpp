#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;

  scanf("%d", &N);

  if(N < 2){
    printf("2\n");
  }
  else if((N % 2) == 0){
    printf("%d\n", N);
  }else{
    printf("%d\n", (N*2));
  }
  return 0;
}
