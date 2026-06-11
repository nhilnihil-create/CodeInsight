#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int n;
  cin >> s;
  n = s.length();
  if (s[n-1] == '1' || s[0] == '0' || s[n-2] == '0') {
    cout << -1 << endl;
    return 0;
  }
  int repeat;
  if (n % 2 == 0) repeat = n/2;
  else repeat = (n-1) / 2;
  for (int i=0; i<repeat; i++) {
    if (s[i] != s[n-i-2]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int current_node = 1;
  for (int i=1; i<repeat; i++) {
    if (s[i] == '1') {
      for (int j=current_node+1; j<=i+2; j++) {
        cout << current_node << " " << j << endl;
      }
      current_node = i+2;
    }
  }
  for (int i=current_node+1; i<=n; i++) {
    cout << current_node << " " << i << endl;
  }
}
