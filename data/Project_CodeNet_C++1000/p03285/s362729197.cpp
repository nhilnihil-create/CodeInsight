#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  for(int i = 0; i <= n; i++) {
    if((n-4*i) >= 0 & (n-4*i)%7 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
