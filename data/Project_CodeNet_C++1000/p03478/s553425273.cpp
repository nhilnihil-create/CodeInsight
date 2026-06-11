#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int answer = 0;
  for (int i = 0; i <= N; ++i) {
    int sum = 0;
    for (char s : to_string(i)) {
      sum += s - '0';
    }
    if (A <= sum && sum <= B) {
      answer += i;
    }
  }
  cout << answer << endl;
}