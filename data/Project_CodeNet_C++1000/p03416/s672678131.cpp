#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,total = 0;
  cin >> a >> b;
  for (int i = a; i < b+1; i++) {
    string str = to_string(i);
    if (str.at(0) == str.at(4) && str.at(1) == str.at(3)) {
      total++;
    }
  }
  cout << total << endl;
}
