#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> fees(4);
  for (int i = 0; i < 4; i++) {cin >> fees.at(i);}
  int ans = 0;
  ans += min(fees.at(0), fees.at(1));
  ans += min(fees.at(2), fees.at(3));
  cout << ans << endl;
}