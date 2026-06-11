#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int a;

  cin >> n >> a;

  int amari = n % 500;
  if (amari > a)
    cout << "No" << endl;
  else if (amari <= a)
    cout << "Yes" << endl;
}
