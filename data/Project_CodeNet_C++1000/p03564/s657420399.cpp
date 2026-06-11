#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K, sum = 1;
  cin >> N >> K;
  rep(i, N){
  if(sum + K <= sum * 2){
    sum += K;
   }else{
    sum *= 2;
   }
  }
  cout << sum <<endl;
  return 0;
}
