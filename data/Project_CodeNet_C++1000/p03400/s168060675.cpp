#include <iostream>

using namespace std;

int main(){
  int N, D, X;
  cin >> N >> D >> X;
  int A[N];
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  int ans = 0;

  for (int i = 0; i < N; i++){
    int tmp = 0;
    while ((tmp + 1) <= D){
      tmp += A[i];
      ans++;
    }
  }
  printf("%d\n", ans + X);
  
}
