#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  string a;
  cin >> a;
  int r = 0, b = 0;
  for(int i = 0; i < n; ++i) {
    if(a[i] == 'R') {
      r += 1;
    } else {
      b += 1;
    }
  }
  if(r > b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
