#include <bits/stdc++.h>
using namespace std;

int main() {
  char n[4];
  cin >> n[0] >> n[1] >> n[2] >> n[3];
  if (((n[0] == n[1]) && (n[1] == n[2])) || ((n[1] == n[2]) && (n[2] == n[3])))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}