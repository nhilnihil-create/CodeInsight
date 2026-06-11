// ABC_103_B
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;

  int len = t.size();

  bool flag = false;

  for (int i = 0; i < len; ++i) {
    int tmp = t.compare(s);

    if(tmp == 0) {
      flag = true;
      break;
    }
    else s = s[len-1] + s.substr(0, len-1);
  }

  //cout << s << "\n";
  //cout << s.size() << "\n";
  //cout << t << "\n";
  
  if (flag) cout << "Yes" << "\n";
  else cout << "No" << "\n";

  return 0;
  
}
