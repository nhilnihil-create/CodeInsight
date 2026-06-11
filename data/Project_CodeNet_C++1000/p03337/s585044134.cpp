#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;

  auto ans = max({A + B, A - B, A * B});

  cout << ans << "\n";

  return 0;
}