#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, P;
  cin >> N >> P;
  if(N == 1){
    cout << P << endl;
    return 0;
  } else if (N >= 64) {
    cout << 1 << endl;
    return 0;
  }
  long ans = 1;
  vector<long> data((long)(sqrt(P) + 1));
  for(long i = 2; i <= sqrt(P); i++){
    while(P % i == 0){
      data.at(i)++;
      P /= i;
    }
    if(data.at(i) >= N)ans *= pow(i, data.at(i) / N);
  }
  cout << ans << endl;
  return 0;
}