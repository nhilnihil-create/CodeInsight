#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

int main(){
  int N;
  scanf("%d", &N);
  int Acount=0;
  int Bcount=0;
  int ABcount=0;
  int originalcount = 0;
  for (int i=0; i<N; i++){
    std::string S;
    std::cin >> S;
    char next='A';
    int index=0;
    while(index<S.length()){
      if (S[index]==next){
        if (next=='B'){
          originalcount++;
          next='A';
        } else if (next=='A'){
          next='B';
        }
      } else if (S[index]=='A'){
        next='B';
      } else {
        next='A';
      }
      index++;
    }

    if (S[0]=='B' && S[S.length()-1]=='A'){
      ABcount++;
    }
    if (S[0]=='B'){
      Bcount++;
    }
    if (S[S.length()-1]=='A'){
      Acount++;
    }
  }
  //printf("original=%d\n", originalcount);
  if (ABcount==Acount && ABcount==Bcount){
    printf("%d\n", originalcount+std::max(0, ABcount-1));
  } else {
    printf("%d\n", originalcount+std::min(Acount, Bcount));
  }
  return 0;
}
