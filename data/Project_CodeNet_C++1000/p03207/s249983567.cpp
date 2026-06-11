#include <iostream>

using namespace std;

int main() {

  int n, s = 0, m = 0, l = 0;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> l;
    s += l;
    m = max(m, l);
  }
  cout << s - m + (m / 2);
  return 0;
}
