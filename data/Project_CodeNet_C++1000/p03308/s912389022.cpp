#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int a[n];
  int x = 0;
  int y = 1000000000;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    if (a[i] > x)
      x = a[i];
  }
  for(int i = 0; i < n; i++) {
    if (a[i] < y)
      y = a[i];
  }
  cout << x - y;
}
  