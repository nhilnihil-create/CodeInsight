#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int64_t a = 2, b = 1;
  for (int i = 0; i < N; i++)
  {
    b += a;
    a = b - a;
  }
  cout << a << endl;
}