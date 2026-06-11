#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> list = {111,222,333,444,555,666,777,888,999};
  for(int i=0; i<9; i++) {
    if(list.at(i) >= n) {
      cout << list.at(i) << endl;
      return 0;
    }
  }
}