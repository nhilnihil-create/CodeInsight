#include <bits/stdc++.h>
using namespace std;
int main() 
{
  string s; cin >> s;
  int firstTwo = (((int)s[0] -48) * 10) + (int)(s[1] - 48);
  int lastTwo = (((int)s[2] - 48) * 10) + (int)(s[3] - 48);

  if(firstTwo <= 12 && firstTwo)
  {
    if(lastTwo <= 12 && lastTwo)
      cout << "AMBIGUOUS";
    else
      cout << "MMYY";
  }
  else
  {
    if(lastTwo <= 12 && lastTwo)
      cout << "YYMM";
    else
      cout << "NA";
  }
  cout << endl;
}