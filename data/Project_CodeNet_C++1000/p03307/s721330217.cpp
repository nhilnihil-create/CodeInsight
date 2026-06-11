#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  if (N % 2 == 0)
    cout << N << "\n";
  else
    cout << N * 2 << "\n";

  return 0;
}