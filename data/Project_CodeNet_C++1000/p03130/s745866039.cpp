#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t a, yes = 1;
  vector<int64_t> C(4, 0);
  for (int i = 0; i < 6; i++)
  {
    cin >> a;
    a--;
    C.at(a)++;
  }
  for (auto c : C)
  {
    if (c == 0 || c == 3)
      yes = 0;
  }
  cout << (yes ? "YES" : "NO") << endl;
}