#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string S, T;
  cin >> S >> T;

  vector<int> s(26, -1);
  vector<int> t(26, -1);

  int count_s = 0;
  int count_t = 0;
  rep(i, S.size())
  {
    char c_s = S[i] - 'a';
    if (s[c_s] == -1)
    {
      s[c_s] = count_s;
      count_s++;
    }

    char c_t = T[i] - 'a';
    if (t[c_t] == -1)
    {
      t[c_t] = count_t;
      count_t++;
    }

    if (s[c_s] != t[c_t])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
