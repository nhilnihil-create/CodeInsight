#include <bits/stdc++.h>
using namespace std;


int main() {

  int N, K;
  cin >> N >> K;

  long long answer = 0;

  for (int b = 1; b <= N; b++) {
    int p = N / b;
    int r = N % b;
    answer += (long long) p * max(0, b - K);
    answer += max(0, (r - K + 1));
    if (K == 0) {
      answer -= 1;
    }
  }

  cout << answer << endl;

}