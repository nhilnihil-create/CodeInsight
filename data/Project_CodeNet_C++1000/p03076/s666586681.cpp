#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> ryori(5);
  for (int i = 0; i < 5; i++) {
    cin >> ryori.at(i);
  }
  
  vector<int> mod(5);
  bool bo = true;
  int sum = 0;
  int last = 9;
  
  for (int i = 0; i < 5; i++) {
    mod.at(i) = ryori.at(i) % 10;
    if (mod.at(i) != 0) {
      bo = false;
      sum += ((ryori.at(i) / 10) + 1) * 10;
      last = min(last, mod.at(i));
    }
    else {
      sum += ryori.at(i);
    }
  }
  if (bo) {
    cout << sum << endl;
  }
  else {
    cout << sum - (10 - last) << endl;
  }
}
