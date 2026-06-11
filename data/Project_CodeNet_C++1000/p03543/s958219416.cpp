#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n / 1000 == n / 100 % 10 && n / 100 % 10 == n / 10 % 10 ) {
    cout << "Yes" << endl;
  } else if(n / 100 % 10 == n / 10 % 10 && n / 10 % 10 == n % 10) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}