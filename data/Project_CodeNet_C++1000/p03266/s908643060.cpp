#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, K;
  cin >> N >> K;

  long long answer = 0;

  if (K % 2 == 0) {
    long long c1 = N / K;
    long long c2 = N / (K / 2) - c1;
    answer = c1 * c1 * c1 + c2 * c2 * c2;
  } else {
    long long c = N / K;
    answer =(long long) c * c * c;
  }

  cout << answer << endl;

  return 0;

}