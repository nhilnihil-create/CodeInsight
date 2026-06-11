#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, K;
  cin >> A >> B >> K;
  int cnt = 0;
  int i = min(A, B);
  // O(min(A, B))のアルゴリズム
  while (i > 0)
  {
    if (A % i == 0 && B % i == 0)
    {
      cnt++;
    }
    if (cnt == K)
    {
      break;
    }
    i--;
  }
  cout << i << endl;
}