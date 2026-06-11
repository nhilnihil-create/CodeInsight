#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int price = 700;
  cin >> s;
  if(s[0] == 'o') price = price +100;
  if(s[1] == 'o') price = price +100;
  if(s[2] == 'o') price = price +100;
  cout << price << endl;
}
