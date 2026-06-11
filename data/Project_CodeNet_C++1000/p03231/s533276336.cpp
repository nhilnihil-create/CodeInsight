#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N,M;
  string S,T;
  cin >> N >> M >> S >> T;
  long long n = N;
  long long m = M;
  long long ans1 = 1;
  
  for (long long i = 2; i <= min(N,M); i++) {
    if (n % i == 0 && m % i == 0){
      for (int j = 0; j < 20; j++) {
        if (n % i == 0 && m % i == 0){
          n /= i;
          m /= i;
          ans1 *= i;
        }
        else {
          break;
        }
      }
    }
    if (n == 1 || m == 1){
      break;
    }
  }
  
  long long ans2 = N * M / ans1;
  long long A = ans2 / M;
  long long B = ans2 / N;
  
  for (int i = 0; i < ans1; i++) {
    if (S.at(i*A) != T.at(i*B)){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans2 << endl;
}
          
    