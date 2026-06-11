#include <bits/stdc++.h>
using namespace std;

int main() {
  int x = 0;
  string n;
  cin >> n;
  int H = stoi(n);

  for (int i = 0; i < n.size(); i++) {
    x += n.at(i) - '0';
  }

  if (H % x == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

}