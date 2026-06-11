#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,P,answer = 1,frequency;
  cin >> N >> P;
  if (N == 1) {
    cout << P;
    return 0;
  }
  for (int i = 2; 1ll*i*i <= P; i++) {
    for (frequency = 0; !(P%i); frequency++, P /= i);
    answer *= (long long)pow(i,frequency/N);
  }
  cout << answer;
}