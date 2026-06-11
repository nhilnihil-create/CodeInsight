#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int64_t max(int64_t a, int64_t b)
{
  if (a > b)
    return a;
  else
    return b;
}
int64_t min(int64_t a, int64_t b)
{
  if (a < b)
    return a;
  else
    return b;
}
void abc83d()
{
  string S;
  cin >> S;
  int64_t m = S.length();
  for (int i = 1; i < S.length(); i++)
  {
    if (S[i] != S[i - 1])
    {
      m = min(m, max(i, S.length() - i));
    }
  }
  cout << m;
}
int main(void)
{
  abc83d();
  return 0;
}
