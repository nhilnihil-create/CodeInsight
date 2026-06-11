#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
  int i,A,B,C,D,S;
  
  cin >> S;
  A = S/1000;
  B = (S/100)%10;
  C = (S/10)%10;
  D = S%10;
  
  if(A+B+C+D==7) {
    printf("%d+%d+%d+%d=7\n", A, B, C, D);
  } else if(A+B+C-D==7) {
    printf("%d+%d+%d-%d=7\n", A, B, C, D);
  } else if(A+B-C+D==7) {
    printf("%d+%d-%d+%d=7\n", A, B, C, D);
  } else if(A+B-C-D==7) {
    printf("%d+%d-%d-%d=7\n", A, B, C, D);
  } else if(A-B+C+D==7) {
    printf("%d-%d+%d+%d=7\n", A, B, C, D);
  } else if(A-B+C-D==7) {
    printf("%d-%d+%d-%d=7\n", A, B, C, D);
  } else if(A-B-C+D==7) {
    printf("%d-%d-%d+%d=7\n", A, B, C, D);
  } else if(A-B-C-D==7) {
    printf("%d-%d-%d-%d=7\n", A, B, C, D);
  }

  return 0;
}