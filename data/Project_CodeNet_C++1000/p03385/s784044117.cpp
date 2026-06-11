#include <bits/stdc++.h>
using namespace std;
int main() {
  string A;
  cin >> A;
  char a, b, c;
  a = A.at(0);
  b = A.at(1);
  c = A.at(2);
  int ans;
  if(!(a == b)) {
    ans++;
  }
  if(!(c == b)) {
    ans++;
  }
  if(!(a == c)) {
    ans++;
  }
  if(ans == 3) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}