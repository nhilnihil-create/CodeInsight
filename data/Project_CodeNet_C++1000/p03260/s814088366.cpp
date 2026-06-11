#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;

  int ans = false;

  for (int i = 0; i < 3; i++)
  {
    if (A * B * i % 2 == 1)
      ans = true;
  }

  cout << (ans ? "Yes" : "No") << endl;
}
