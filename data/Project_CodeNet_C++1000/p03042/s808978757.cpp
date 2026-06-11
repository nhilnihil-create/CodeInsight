#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  string e = "XX", f = "XX";
  e.at(0) = a;
  e.at(1) = b;
  f.at(0) = c;
  f.at(1) = d;
  int g = stoi(e);
  int h = stoi(f);
  string ans;
  if(1<=g && g<=12 && 1<=h && h<=12) ans ="AMBIGUOUS";
  else if(0<=g && g<=99 && 1<=h && h<=12) ans ="YYMM";
  else if(1<=g && g<=12 && 0<=h && h<=99) ans ="MMYY";
  else ans ="NA";
  cout << ans << endl;
}
