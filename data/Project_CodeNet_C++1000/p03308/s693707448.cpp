#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p = 0,q = 1000000001;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    p = max(p,a);
    q = min(q,a);
  }
  cout << p - q << endl;
  return 0;
}