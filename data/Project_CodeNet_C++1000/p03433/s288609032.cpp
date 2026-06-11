#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (x%500 <= y) {
    cout << "Yes" << endl;
  }
  if (x%500 > y)  {
    cout << "No" << endl;
}
}