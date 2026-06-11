#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N; scanf("%d", &N);
  
   vector<vector<char>> S(N,vector<char>(N));
  
  int cnt = 0;
  
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < N; j++){ cin >> S[i][j];}}
  
  vector<vector<char>> T(N,vector<char>(N));
 
    for(int B = 0; B < N; B++){
      
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          
          T[i][j] = S[i][(j+B)%N];
          
          
           
        }
      }
      
      bool flag = true;
     

      for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
          
          if( T[i][j] != T[j][i]){ flag = false; break;}
        }
      }
      
      if(flag){cnt++; }
     
    }
  
  
  printf("%d\n", cnt*N); return 0;
}
     
        