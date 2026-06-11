#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s, t; cin >> s >> t;
  bool res = false;
  for (int i = 0; i < (int)s.size(); i++)
  {
    int sid = i;
    int cnt = 0;
    for (int j = 0; j < (int)t.size(); j++)
    {
      if (sid > (int)s.size() - 1) sid %= s.size();
      if (s[sid] == t[j]) { cnt++; sid++; }
      else 
        break;
      if (cnt == (int)t.size()) { res = true; break; }
    }
    if (res == true) break;
  }
  cout << (res ? "Yes" : "No") << endl;
}