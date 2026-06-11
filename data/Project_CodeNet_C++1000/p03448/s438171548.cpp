#include <iostream>
using namespace std;
int main()
{
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int ans = 0;
  for (int a = 0; a <= A; a++) {
    for (int b = 0; b <= B; b++) {
      int c = (X - a*500 - b*100) / 50;
      if (0 <= c && c <= C) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
