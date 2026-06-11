#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> ABC(3);
  cin >> ABC.at(0) >> ABC.at(1) >> ABC.at(2);
  sort(ABC.begin(), ABC.end());
  int ans = (ABC.at(2) - ABC.at(1));
  ABC.at(0) += (ABC.at(2) - ABC.at(1));
  ABC.at(1) += (ABC.at(2) - ABC.at(1));
  if ((ABC.at(2) - ABC.at(0)) % 2 == 1) {
    ans += ((ABC.at(2) - ABC.at(0)) / 2);
    ans += 2;
    cout << ans << endl;
  }
  else {
    ans += ((ABC.at(2) - ABC.at(0)) / 2);
    cout << ans << endl;
  }
}
  