#include <iostream>
using namespace std;

int main()
{
  string s, res = "";
  cin >> s;
  int prefix = stoi(s.substr(0, 2));
  int suffix = stoi(s.substr(2, 2));
  if(prefix == 0 && suffix == 0 ||
    prefix == 0 && suffix > 12 ||
    prefix > 12 && suffix == 0 ||
    prefix > 12 && suffix > 12)
  {
    res = "NA";
  }
  else if((prefix > 12 || prefix == 0) && suffix <= 12)
    res = "YYMM";
  else if(prefix <= 12 && (suffix > 12 || suffix == 0))
    res = "MMYY";
  else
    res = "AMBIGUOUS";
  
  cout << res << endl;
  return 0;
}