#include <iostream>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  int k = b-a;
  int ans = k*(k-1)/2 - a;
  cout << ans << endl;
  return 0;
}