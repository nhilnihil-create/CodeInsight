#include <iostream>
using namespace std;
int main() {
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  if(k%2 == 1) cout << b-a;
  else cout << a-b;
}