#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin >> N;
  int h, n, w;
  for (long long i = 1; i <= 3500; i++){
    for (long long j = 1; j <= 3500; j++){
      long long a = 4 * i * j - N * (i + j);
      long long b = N * i * j;
      if (a > 0){
        if (b % a == 0){
          h = i;
          n = j;
          w = b / a;
        }
      }
    }
  }
  cout << h << ' ' << n << ' ' << w << endl;
}
