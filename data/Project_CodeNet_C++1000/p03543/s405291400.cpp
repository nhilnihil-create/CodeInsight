#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,n1,n2,n3,n4;
  cin >> n;
  n1 = n % 10;
  n2 = n / 10 % 10;
  n3 = n / 10 / 10 % 10;
  n4 = n / 10 / 10 / 10 % 10;
  if (n2 == n3 && (n1 == n2 || n3 == n4)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

}
