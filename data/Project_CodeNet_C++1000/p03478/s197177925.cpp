#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
  int simn = 0;
  
  while (n > 0) {
    simn += n % 10;
    n /= 10;
  }
  return simn;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int answer = 0;
  
  for (int i = 1; i <= N; i++) {
      int sim = sum(i);
      if (sim >= A && sim <= B) {
        answer += i;
      }
  }
  cout << answer << endl;
}