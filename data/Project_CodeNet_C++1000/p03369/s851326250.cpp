#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  int ans = 700;
  cin >> s;
  ans += count(s.begin(), s.end(), 'o') * 100;
  cout << ans << endl;
  return 0;
}