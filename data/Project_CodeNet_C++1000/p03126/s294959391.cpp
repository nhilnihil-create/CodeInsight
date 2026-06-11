#include <bits/stdc++.h>
using namespace std;
int main(void){
   
  int N,M,ans = 0;
  cin >> N >> M;
  int data[N][M];
  
  for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
          data[i][j] = 0;
      }
  }
  
  for(int i=0;i<N;i++){
      int K;
      cin >> K;
      for(int j=0;j<K;j++){
          int A_i;
          cin >> A_i;
          data[i][A_i-1] = 1;
      }
  }
  
   for(int i=0;i<M;i++){
       int sum = 0;
      for(int j=0;j<N;j++){
          if(data[j][i] == 1) sum++;
      }
      if(sum == N) ans++;
  }
  
  cout << ans << endl;
}