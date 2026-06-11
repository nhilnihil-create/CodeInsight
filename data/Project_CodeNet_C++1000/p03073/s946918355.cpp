#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string S;
  cin >> S;

  int cnt_w = 0;
  int cnt_b = 0;
  rep(i, S.size())
  {
    if (i % 2 == 0)
    {
      if (S[i] == '0')
      {
        cnt_w++;
      }
      else
      {
        cnt_b++;
      }
    }
    else
    {
      if (S[i] == '1')
      {
        cnt_w++;
      }
      else
      {
        cnt_b++;
      }
    }
  }

  cout << std::min(cnt_w, cnt_b) << endl;

  return 0;
}
