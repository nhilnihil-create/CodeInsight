#include<iostream>

using namespace std;

int main(){
  int N, M, C;
  cin >> N >> M >> C;
  int B[M], A[N][M];

  for(int i = 0; i < M; i++){
    cin >> B[i];
  }
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> A[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++){
    int s = 0;
    for (int j = 0; j < M; j++){
      s += A[i][j] * B[j];
    }
    s += C;
    if(s > 0){
      ans++;
    }
  }
  
  printf("%d\n", ans);
}
