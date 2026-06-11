#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int C[N-1], S[N-1], F[N-1];
  for (int i = 0; i < N-1; i++){
    cin >> C[i] >> S[i] >> F[i];
  }
  int ans[N-1];

  for (int i = N - 2; i >= 0; i--){
    int tmp = S[i] + C[i];

    for (int j = i+1; j < N - 1; j++){
      if (S[j] >= tmp){
        tmp = S[j] + C[j];
      }else{
        int t = tmp - S[j];
        if (t <= F[j]){
          t = F[j] - t;
        }else{
          int f = t % F[j];
          if (f==0) {
            t = 0;
          }else{
            t = F[j] - f;
          }
        }
        tmp += C[j] + t;
      }
    }
    ans[i] = tmp;
  }
  
  for (int i = 0; i < N-1; i++){
    printf("%d\n", ans[i]);
  }
  printf("0\n");
  
}
