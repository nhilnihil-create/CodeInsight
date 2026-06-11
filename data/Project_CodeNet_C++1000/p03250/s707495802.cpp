#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  int temp1 = A * 10 + B + C;
  int temp2 = B * 10 + A + C;
  int temp3 = C * 10 + A + B;

  cout << max({temp1, temp2, temp3}) << endl;
}
