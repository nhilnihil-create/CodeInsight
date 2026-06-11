#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string t = s.substr(0,2);
  string u = s.substr(2,2);
  int a = atoi(t.c_str());
  int b = atoi(u.c_str());
  int x = 0;
  if(1 <= a && a <= 12) {
    x += 1;
  }
  if(1 <= b && b <= 12) {
    x += 2;
  }
  switch(x) {
    case 0:
      cout << "NA" << endl;
      break;
    case 1:
      cout << "MMYY" << endl;
      break;
    case 2:
      cout << "YYMM" << endl;
      break;
    case 3:
      cout << "AMBIGUOUS" << endl;
      break;
  }
}