#include <iostream>

using namespace std;

int main(){
  int N, A, B, ans = 0;
  cin >> N >> A >> B;

  for (int i = 1; i <= N; i++){
    // 各桁を足した値
    int ss = 0, n = i;
    while(n != 0){
      int s = n%10;
      n /= 10;
      ss += s;
    }
    
    if(A <= ss && B >= ss){
      ans += i;
    }
  }
  printf("%d\n", ans);
}
