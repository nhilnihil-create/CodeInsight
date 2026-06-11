#include <iostream>
using namespace std;

int main() {
  int a;
  string ans = "No";
  cin >> a;
  
  for (int i = 0; i <= 25; i++) {
    for (int j = 0; j <= 15; j++) {
        if (i*4 + j*7 == a) ans = "Yes";
    }
  }  
  cout << ans << endl;
}