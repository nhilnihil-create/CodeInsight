#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  int ans = 1000000000;
  for (int i = 0; i < N; i++){
    int tmp = A[i], c = 0;
    while (tmp%2 == 0){
      tmp /= 2;
      c++;
    }
    if (ans > c){
      ans = c;
    }
  }
  printf("%d\n", ans);
}
