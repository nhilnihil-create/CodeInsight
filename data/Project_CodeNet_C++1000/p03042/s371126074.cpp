#include <iostream>

using namespace std;

int main() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  int i, j;
  i = (a - '0') * 10 + (b - '0');
  j = (c - '0') * 10 + (d - '0');
  if ((0 < i && i < 13) && (0 < j && j < 13))
    cout << "AMBIGUOUS" << endl;
  else if ((0 < i && i < 13) && not (0 < j && j < 13))
    cout << "MMYY" << endl;
  else if (not (0 < i && i < 13) && (0 < j && j < 13))
    cout << "YYMM" << endl;
  else
    cout << "NA" << endl;
}