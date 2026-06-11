#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main()
{
  string A;
  cin >> A;
  for (int bit = 0; bit < (1 << 3); bit++)
  {
    bitset<3> s(bit);
    //cout << s << endl;
    float sum = A.at(0) - '0';
    rep(i, 3)
    {
      if (s.test(i))
      {
        sum += A.at(i + 1) - '0';
      }
      else
      {
        sum -= A.at(i + 1) - '0';
      }
    }
    if (sum == 7)
    {
      rep(i, 3)
      {
        cout << A.at(i);
        if (s.test(i))
        {
          cout << '+';
        }
        else
        {
          cout << '-';
        }
      }
      cout << A.at(3) << "=7" << endl;
      exit(0);
    }
  }
}
