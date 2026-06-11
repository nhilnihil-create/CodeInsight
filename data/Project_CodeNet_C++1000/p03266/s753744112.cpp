#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,K;
  cin >> N >> K;

  int64_t div= N/K;
  int64_t ans= (K%2 != 0)  ? div* div* div
              :(N%K < K/2) ? div* div* div* 2
                           : div* div* div+ (div+ 1)* (div+ 1)* (div+ 1);
  cout << ans << endl;
}