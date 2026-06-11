#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int A, B;
  cin >> A >> B;
  int ans = A * B - A - B + 1;
  cout << ans << endl;
  return 0;
}