#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int s; cin >> s;
  int u = s / 100;
  int l = s % 100;
  bool bu = (0 < u && u <= 12);
  bool bl = (0 < l && l <= 12);

  if (bu && bl)  cout << "AMBIGUOUS" << endl;
  else if (bu)   cout << "MMYY" << endl;
  else if (bl)   cout << "YYMM" << endl;
  else           cout << "NA" << endl;
}
