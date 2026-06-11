#include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s ;
  int s_1 = s / 100;
  int s_2 = s / 10 - 10 * s_1 ;
  int s_3 = s - 100 * s_1 - 10 * s_2 ;
  cout << s_1 + s_2 + s_3  << endl;
}