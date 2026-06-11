#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> div;
  for (int i = 1; i <= 100; i++) {
    if (a % i == 0 && b % i == 0) {
      div.push_back(i);
    }
  }
  cout << div.at(div.size() - k) << endl;
}
