#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;
typedef long long ll;

char S[310][310];

int main(){
 int N; scanf("%d", &N);
  int cnt = 0;
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){  
      scanf(" %c", &S[i][j]);
    }
  }

  
  bool flag;
  for(int A = 0; A < N; A++){ 
    flag = true;
    char T[310][310];
    
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){ 
        T[(i+A)%N][j] = S[i][j];}
    }
    
    
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if( T[i][j] != T[j][i]){ flag = false; break;
                               }
      }
    }
    
    if( flag){ cnt++;}
  }
  
  printf("%d\n", N*cnt); return 0;
}
    
  
  