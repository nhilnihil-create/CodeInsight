#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  int sum = 0, ans = 0;
  int k;
  for(int i = 1; i <= N; i++){
    sum = 0;
    k = i;
    for(int j = 0; j < 5; j++){
      sum += k % 10;
      k /= 10;
    }
    if(A <= sum && sum <= B){
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}