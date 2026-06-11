#include<bits/stdc++.h>
using namespace std;

int main () {
  int N, A, B;
  scanf("%d%d%d",&N,&A,&B);
  
  printf("%d ",min(A,B));
  if (A + B <= N) {
    printf("%d\n",0);
  }
  else {
    printf("%d\n",A+B-N);
  }
}