#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, T, ans = 0;
  cin >> A >> B >> T;
  int temp = A;

  for (int i = 0; i < T + 1; i++) {
    if (i == temp) {
      ans += B;
      temp += A;
    }
  }

  cout << ans << endl;
}
