#include <iostream>
using namespace std;

int main()
{
  string s;
  int cnt = 0;
  int i;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'x')
      cnt++;
  }
  if (cnt > 7)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
