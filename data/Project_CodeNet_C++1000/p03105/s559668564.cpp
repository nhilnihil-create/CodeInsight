#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  int count = 0;
  cin >> A >> B >> C;
  for (int i = 0; i < C; i++)
  {
    B -= A;
    if (B < 0)
    {
      cout << count << endl;
      break;
    }
    else
    {
      count++;
    }
  }
  if (C == count)
  {
    cout << count << endl;
  }
}