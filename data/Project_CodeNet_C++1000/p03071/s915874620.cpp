#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  int A, B, score;
  cin >> A >> B;

  score = 0;
  for (int i = 0; i < 2; i++) {
    if (A <= B) {
      score += B;
      B--;
    } else {
      score += A;
      A--;
    }
  }
  cout << score << endl;
}
