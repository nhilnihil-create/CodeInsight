#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int answer;

  answer = A * X + B * Y;
  answer =
      min(answer, X > Y ? 2 * Y * C + A * (X - Y) : 2 * X * C + B * (Y - X));
  answer = min(answer, 2 * max(X, Y) * C);

  cout << answer << endl;
}
