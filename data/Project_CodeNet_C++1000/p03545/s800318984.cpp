#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> v(4);
  vector<char> op(4);
  for (int i = 0; i < 4; i++)
  {
    int buf = n % 10;
    n /= 10;
    v.at(i) = buf;
  }
  reverse(v.begin(), v.end());

  for (int i = 0; i < 8; i++)
  {
    int sum = v.at(0);
    for (int j = 0; j < 3; j++)
    {
      if (i & (1 << j))
      {
        op[j] = '+';
        sum += v[j + 1];
      }
      else
      {
        op[j] = '-';
        sum -= v[j + 1];
      }
    }
    if (sum == 7)
    {
      break;
    }
  }
  for (int i = 0; i < 3; i++)
  {
    cout << v.at(i) << op.at(i);
  }
  cout << v.at(3) << "=7" << endl;
}
