#include <iostream>

using namespace std;

int main() {

  int n, s = 1e9, m = 0, l = 0;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> l;
    m = max(m, l);
    s = min(s, l);
  }
  cout << m - s;
  return 0;
}
