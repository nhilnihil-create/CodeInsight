#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, X;
  cin >> A >> B >> X;
  if (X - A < 0)
    cout << "NO" << endl;
  else if (X - A <= B)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
