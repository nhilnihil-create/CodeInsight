#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> time(5);
  for(int i = 0; i < 5; i++) {
    cin >> time.at(i);
  }
  int ans = 1000;
  for(int i = 0; i < 5; i++) {
    int total = 0;
    total += time.at(i);
    for(int j = 0; j < 5; j++) {
      if(j == i) {
        continue;
      }
      total += ((time.at(j) - 1) / 10) * 10 + 10;
    }
    if(total < ans) {
      ans = total;
    }
  }
  cout << ans << endl;
}