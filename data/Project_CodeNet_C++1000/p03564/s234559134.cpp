#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N = 0, K = 0;
  cin >> N >> K; 
  int A, B;
  int ans = 1;
  for(int n = 0; n < N; n++){
    A = ans * 2;
    B = ans + K;
    if(A >= B){
      ans = B;
    }else{
      ans = A;
    }
  }
  cout << ans << endl;
}