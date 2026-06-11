#include <bits/stdc++.h>
using namespace std;
int main() {
  int X,answer=0;
  cin >> X;
  if (X < 4) {
    cout << 1;
    return 0;
  }
  for (int b = 2; b < X; b++) {
    for (int Y = b*b; Y <= X; Y *= b) {
      answer=max(answer,Y);
    }
  }
  cout << answer;
}