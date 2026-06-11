#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  char x, y;
  cin >> x >> y;
  int a = x - 'A';
  int b = y - 'A';

  if(a > b) {
    cout << ">";
  } else if(a < b) {
    cout << "<";
  } else {
    cout << "=";
  }


  return 0;
}

