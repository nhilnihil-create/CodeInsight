#include <iostream>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int c[M+1];
  for (int i = 1; i < M+1; i++){
    c[i] = 0;
  }
  
  for (int i = 0; i < N; i++){
    int K;
    cin >> K;
    for (int j = 0; j < K; j++){
      int tmp;
      cin >> tmp;
      c[tmp]++;
    }
  }
  
  int ans = 0;
  for (int i = 1; i < M+1; i++){
    if (c[i]==N) ans++;
  }
  printf("%d\n",ans);
}
