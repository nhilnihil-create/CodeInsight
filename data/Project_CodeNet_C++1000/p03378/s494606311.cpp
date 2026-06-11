#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N, M, X;
  cin >> N >> M >> X;
  int A[M];
  for (int i = 0; i < M; i++){
    cin >> A[i];
  }

  int ans = 0;
  for (int i = 0; i < M; i++){
    if (A[i] > X){
      ans = min(ans, M - i);
      break;
    }else{
      ans++;
    }
    
  }
  
  printf("%d\n", ans);
  
}
