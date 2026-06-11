#include <bits/stdc++.h>
using namespace std;

int main() {
  long s, flag = 0, ans = 0;
  cin >> s;
  long tmp = s;
  vector<int> item(1000000);
  item.at(0) = tmp;
  
  for (int i = 1; i < 1000000; i++) {
    if (tmp%2 == 0) tmp = tmp / 2;
    else tmp = 3 * tmp + 1;
    item.at(i) = tmp;
    for (int j = 0; j < i; j++) {
      if (item.at(j) == tmp) {
        ans = i + 1;
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }
  
  cout << ans << endl;
}