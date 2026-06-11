#include <bits/stdc++.h>
using namespace std;
int main() {
 string a;
  cin >> a;
  sort(a.begin(), a.end());
  if (a[0] == 'a' && a[1] == 'b' && a[2] == 'c') {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}